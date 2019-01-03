#ifndef _H_IMGPARSE
#define _H_IMGPARSE

#define READBUF 512

#define FALSE 0
#define TRUE  1

void write_lsbs(unsigned char *orig, char *towrite);
void parse_image(char *fname, char *msg);

#endif
