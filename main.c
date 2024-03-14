#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define row 3
#define col 3
int couni , countj ,num_up,num_down,resu;
bool flag=true;
char arr[row][col]={0}; //string is arr of char

//to calc pow
int calc_pow(int base, int exponent) {
  int result = 1;
  for (int i = 0; i<exponent; i++) {
    result *= base;
  }
  return result;
}

//////////////////////////////////////////////////////////////////////////
//to convert char digit to int
int char_to_int(char c) {
  /* if((int)c<=9 && (int)c>=9){
    c-'0';
   }
   else if((int)c<=10 && (int)c>=99){
    c-'0'-'0';
   }*/
  return c-'0';
}



////////////////////////////////////////////////////////////////////////////
//to check if matrix is an Embedia
void is_embedia(char arr[row][col]) {

  // Check inner elements
  for (couni=1 ;couni<row-1 ; couni++) {
    for (countj=0 ;countj<col ;countj++) {

      num_up = char_to_int(arr[couni-1][countj]);
      num_down = char_to_int(arr[couni+1][countj]);
      resu = calc_pow(num_down,num_up);

      // Check if embedia|not
      if (char_to_int(arr[couni][countj]) != resu) {
        flag=false;
      }
    }
  }
    if(flag)
   { printf("\nEmbedia Power Matrix\n");}
    else if(!flag)
    {printf("\n Not an Embedia Power Matrix\n");}
}

//////////////////////////////////////////////////////////////////////


int main()
{
char test_case1[3][3] = {
    {'3', '2', '2'},
    {'8', '9', '4'},
    {'2', '3', '2'}
  };

  is_embedia(test_case1);



}
