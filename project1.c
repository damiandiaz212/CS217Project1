//Damian Diaz (N00821283@students.ncc.edu)
//CSC 217
//Project 1 : Vowels
//project1.c

#include <stdio.h>
#define MAXCHAR 250

//PROTOTYPES
int checkLine(char line[]);
int checkVowels(char line[], int length);
int isVowel(int c);
void saveLine(char line[], int length);

//VARIABLES
char output[1000]; //output array
int outIndex = 0; //output array index

int lowerVowels[] = {'a', 'e', 'i', 'o', 'u'}; //lowercase vowels
int upperVowels[] = {'A', 'E', 'I', 'O', 'U'}; //uppercase vowels

int main(){

  char line[MAXCHAR];

  while(checkLine(line) > 0); //while the line isnt empty

  printf("%s\n", output); //print output

  return 0;
}

//checkLine function
//checks for lines then passes line to check for vowel match
int checkLine(char line[]){

  int c = 0; //stores current char
  int length = 0; //length of line

  while((c = getchar()) != EOF){ //while c has not reached the end of input

    if(c == '\n' || length == MAXCHAR){ //if c has reached a newline or maxcharacters
      break;
    }

    line[length] = c; //assign current index in the line array to current char
    ++length; //increment length

  }

  if(c == EOF && length == 0){ //if c has reached end of input or the line is empty
    return -1;
  }

  line[length] = '\0'; //assign null terminator

  if(checkVowels(line, length) == 1){ //check line for in order vowels

    saveLine(line, length); //saves line to output

  }

  return length;
}

//checkVowels function
//checks a passed line for in order vowels
int checkVowels(char line[], int length){

  int i;
  int count = 0; //current index or vowel its looking for

  for(i = 0; i < length; ++i){

    int c = line[i];

    if(isVowel(c) == 1){ //checking if c is a vowel

      //if c is the vowel that comes next
      if(c == lowerVowels[count] || c == upperVowels[count]){
        count++; //look for next vowel
      }else{
        count = 0; //start over
      }

      if(count == 5){ //if order has been met
        return 1;
      }

    }
  }
  return 0;
}

//isVowel function
//if the character passed is a vowel
int isVowel(int c){

  int i = 0;

  for(i = 0; i < 5; ++i){
    if(c == lowerVowels[i] || c == upperVowels[i]){
      return 1;
    }
  }
  return 0;
}

//saveLine function
//saves a passed char array to the output
void saveLine(char line[], int length){

  //if line meets requirements add line to output array
  for(int i = 0; i < length; i++){
    output[outIndex] = line[i];
    ++outIndex;
  }

  //add linebreak and increment to output
  output[outIndex] = '\n';
  ++outIndex;

}
