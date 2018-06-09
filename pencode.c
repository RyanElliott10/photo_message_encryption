#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#include "pencode.h"
#include "imgparse.h"
#include "safe.h"

/*
 * SUPPORTED FILE EXTENSIONS (FOLLOWS JPEG STANDARDIZED FORMAT)
 * 
 * .jpg
 * .jpeg
 * .jpe
 * .jif
 * .jfif
 * .jfi
 */

int main(int argc, char *argv[])
{
   char *msg;

   if (argc < 3)
   {
      fprintf(stderr, "usage ./pme [ filename ] [ message ]\n");
      exit(EXIT_FAILURE);
   }

   msg = safe_malloc(strlen(argv[2]));
   strcpy(msg, argv[2]);

   parse_image(argv[1], msg);

   return 0;
}
