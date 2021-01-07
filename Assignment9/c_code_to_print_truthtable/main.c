#include <stdio.h>
#include <string.h>

int main() {
	FILE *filePointer;

  char line[] = " \0";

  unsigned int A = 0x00, B = 0x00, Cin = 0x00;
  unsigned int Sum, Cout; 

  unsigned int Sum_func(unsigned int a, unsigned int b, unsigned int c_in); 
  unsigned int Cot_func(unsigned int a, unsigned int b, unsigned int c_in);
  
  filePointer = fopen("table.txt", "w");

  if (filePointer == NULL) {
		printf("table.txt file failed to open.");
	} else {
		printf("The file is now opened.\n");

  fputs(" ____________________\n",filePointer);
  fputs("| A | B |Cin|Sum|Cout|\n",filePointer);
  fputs("|---|---|---|---|----|\n",filePointer);


  for(int i = 0; i < 8; i++) {
    
    fputs("| ",filePointer);  line[0] = A+48; fputs(line,filePointer); 
    fputs(" | ",filePointer); line[0] = B+48; fputs(line,filePointer); 
    fputs(" | ",filePointer); line[0] = Cin+48; fputs(line,filePointer);  
    fputs(" | ",filePointer); line[0] = Sum_func(A,B,Cin)+48; fputs(line,filePointer);
    fputs(" | ",filePointer); line[0] = Cot_func(A,B,Cin)+48; fputs(line,filePointer); 
    fputs("  |\n",filePointer);

    if(i == 3) A = 0x01; //updating A

    if(i % 2 != 0) Cin = 0x00; //updating C
    else Cin = 0x01;

    if(i == 1) B = 0x01; //updating B
    if(i == 3) B = 0x00;
    if(i == 5) B = 0x01;
  }
  fputs("|___|___|___|___|____|\n",filePointer);
  }

	fclose(filePointer);
	printf("The file is now closed.\n");

	return 0;
}

unsigned int Sum_func(unsigned int a, unsigned int b, unsigned int c_in) {
  return ((a)& (!b) & (!c_in)) | ((!a) & (!b) & (c_in)) | ((!a) & (b) & (!c_in)) | ((a) & (b) & (c_in));
}

unsigned int Cot_func(unsigned int a, unsigned int b, unsigned int c_in){
  return ((b) & (c_in)) | ((a) & (b)) | ((a) & (c_in)); 
}
