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

    palavra[i] = int(x[i]) - 48;
  }

  int pot[5] = {0,1,3,7,15};
  
  int pot2[5] = 

{palavra[0] ^ palavra[1] ^ palavra[3] ^ palavra[4] ^ palavra[6] ^ palavra[8] ^ palavra[10] ^ palavra[11] ^ palavra[13] ^ palavra[15],
  palavra[0] ^ palavra[2] ^ palavra[3] ^ palavra[5] ^ palavra[6] ^ palavra[9] ^ palavra[10] ^ palavra[12] ^ palavra[13],
  palavra[1] ^ palavra[2] ^ palavra[3] ^ palavra[7] ^ palavra[8] ^ palavra[9] ^ palavra[10] ^ palavra[14] ^ palavra[15],
  palavra[4] ^ palavra[5] ^ palavra[6] ^ palavra[7] ^ palavra[8] ^ palavra[9] ^ palavra[10],
  palavra[11] ^ palavra[12] ^ palavra[13] ^ palavra[14] ^ palavra[15]};
  
  int count = 0;
  
  for(i = 0; i < 21; i++){

    if (exist_this_element(pot, i, 5)){
      
      hamming += (to_string(pot2[count]));

        count++;
    }
    else{

      hamming += (to_string(palavra[i]));
      
    }
  }

  for( i =0; i < 5;i++){
    
    cout <<"pot2 "<< i <<endl << pot2[i] << endl;

  }
  
  return hamming;
}



int main (void){

  // ler um inteiro de 16 bits.
  int read;
  cin >> read;
  

  string x = bitset<16>(read).to_string();
  string H = Hamming(x);

  cout << "código com redundância:" << H << " num de char: " << H.size() << endl << "código original: " << x << " num de char: " << x.size();
}

