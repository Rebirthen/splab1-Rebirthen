//Fullname: Diana Temirkhan
//Group: 3EN04D

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main (int argc, char **argv)
{
  int cflag = 0;
  int sflag = 0;         //initialize
  int index;
  int ch;
  opterr = 0;
  while ((ch = getopt (argc, argv, "sc")) != -1) //options in case s and c 
    switch (ch)
      {
      case 'c':
        cflag = 1;  //this is flag of cos
        break;
      case 's':
        sflag = 1;   //this is flag of sin
        break;
      case '?':
        fprintf(stderr,"error\n");
        return 1;
      default:
        abort();
      }
  
  if(argc==1){
    printf("usage: sincos angle \nonly sine: sincos -s angle \nonly cosine: sincos -c angle.\n");
  } //Kak Doctors propisal :) tipa esli tam odin tol'ko arg(./sincos) to usage vihodit
  for (index = optind; index < argc; index++){
  double angle = atof(argv[index]);
  
  if (!sflag && !cflag){ //if there is no option
    printf("%f\n",sin(angle));    
    printf("%f\n",cos(angle));
  } else{
    if (sflag){//if there is sin option
      printf("%f\n",sin(angle));
    }
    if (cflag){//if there is cos option
      printf("%f\n",cos(angle));
    }
  }
  break;
  }
  
  return 0;
}