#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>

#include "imgparse.h"
#include "safe.h"

void parse_image(char *fname, char *msg)
{
   int i, fdr, fdw, cont, msglen, msgcount;
   unsigned char buffer[READBUF], writebuf[2];

   fdr      = safe_open(fname, O_RDONLY, 0);
   fdw      = safe_open(fname, O_WRONLY, 0);
   cont     = TRUE;
   msglen   = strlen(msg);
   msgcount = 0;

   memset(buffer, 0, READBUF);
   memset(writebuf, 0, 2);

   while (safe_read(fdr, buffer, READBUF) && cont)  /* Read until it doesn't read any bytes */
   {
      for (i = 0; i < READBUF; i++)
      {
         if (buffer[i] == 0xFF && buffer[i + 1] == 0xD9)  /* JPEG/JPG format specifies 0xFF 0xD9 as markers for EOF */
         {
            printf("%2x %2x\n", buffer[i], buffer[i + 1]);
            cont = FALSE;
            break;
         }

         if (msgcount == msglen)
         {
            cont = FALSE;
            break;
         }
         
         write_lsbs(buffer + i, msg + msgcount);

         writebuf[0] = buffer[i];
         safe_write(fdw, writebuf, 1);
         i && (i + 1) % 4 == 0 ? msgcount++ : msgcount;   /* If i is multiple of 4 (one byte has been written), inrement char position in msg */

         memset(writebuf, 0, 2);

         // printf("%2x%s", buffer[i], (i == (READBUF - 1) || !((i + 1) % 8) ? "\n" : " "));
      }

      memset(buffer, 0, READBUF);
   }

   close(fdr);
   close(fdw);
}

/* CURRENT LOCATION
 *
 * Creates new bytes, writes to file. Must now ensure the message is not larger than
 * the picture.
 * 
 * Accept input from stdin, allow user to enter " string " to take that in, file input, etc
 * 
 * Write decoding as well
 */

/* Accepts byte from picture (orig), byte from message bit shifted n times (towrite)*/
void write_lsbs(unsigned char *orig, char *towrite)
{
   unsigned char cur;

   cur = 3;          /* Set the two lsb so that it can be anded with towrite properly */
   cur &= *towrite;  /* AND to get the correct byte to be written */

   *towrite >>= 2;   /* Bit shift right twice to get to the next two bits to be written */

   // printf("TBA:  %2d   ", cur);
   // printf("ORIG: %2x   ", *orig);

   *orig &= 0xFC;    /* AND so two lsb are 0 */
   // printf("CLER: %2x   ", *orig);
   *orig |= cur;     /* OR so new lsb are correct */
   // printf("NEW:  %2x\n", *orig);
}
