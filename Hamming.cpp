#include <bits/stdc++.h>
#include <string>
using namespace std;

bool exist_this_element(int *vetor, int number, int array_size){

  int i;
  for (i = 0; i < array_size; i++){

    if(vetor[i] == number){
      return true;
    }
  }

  return false;
}

int pot2finder(int number){

  int count = 0;

  while(number != 0){

    if (count == 0 && number == 1 || count == 0 & number == 0){
      return 0;
    }
      
    else{
      number = floor(number/2);
    
      if (number > 1){
      
        count++;
      }
    }
  }
  count++;

  return count;
  
}

string Hamming(string x){


  string hamming = "";
  // vetor com todos os valores dos bits.
  
  int i,x1,x2,x4,x8,x16;

  int palavra[16];

  for(i = 0; i < 16; i++){

    palavra[i] = int(x[i]);
  }

  int pot[5] = {1,2,4,8,16};
  int pot2[5] = {palavra[2] ^ palavra[4] ^ palavra[6] ^ palavra[8] ^ palavra[10] ^ palavra[12] ^ palavra[14],palavra[2] ^ palavra[5]^ palavra[6]^ palavra[9]^ palavra[10]^ palavra[13]^ palavra[14],palavra[4] ^ palavra[5] ^ palavra[6]^ palavra[11]^ palavra[12]^ palavra[13]^ palavra[14],palavra[8] ^ palavra[9]^ palavra[10]^ palavra[11]^ palavra[12]^ palavra[13]^ palavra[14],0};
  

  x1 = palavra[2] ^ palavra[4] ^ palavra[6] ^ palavra[8] ^ palavra[10] ^ palavra[12] ^ palavra[14];

  x2 = palavra[2] ^ palavra[5]^ palavra[6]^ palavra[9]^ palavra[10]^ palavra[13]^ palavra[14];

  x4 = palavra[4] ^ palavra[5] ^ palavra[6]^ palavra[11]^ palavra[12]^ palavra[13]^ palavra[14];

  x8 = palavra[8] ^ palavra[9]^ palavra[10]^ palavra[11]^ palavra[12]^ palavra[13]^ palavra[14];

//x16 = ?????
  int count = 0;
  for(i = 0; i < 24; i++){

    if (exist_this_element(pot, i, 5)){
      hamming = hamming+(char(pot2[count]));

        count++;
    }
    else{

      hamming = hamming+(char(palavra[i]));
    }
  }


  return hamming;
}

int main (void){

  // ler um inteiro de 32 bits.
  int read;
  cin >> read;
  

  string x = bitset<16>(read).to_string();
  string H = Hamming(x);

  cout << H;
}

