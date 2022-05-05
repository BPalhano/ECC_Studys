#include <bits/stdc++.h>
using namespace std;

string Hamming(string x){


  string hamming = "";
  // vetor com todos os valores dos bits.
  
  int i,x1,x2,x4,x8,x16;

  int palavra[16];

  for(i = 0; i < 16; i++){

    palavra[i] = int(x[i]) - 48;
  }
  
  bool bitcheck[21]={true,true,false,true,false,false,false,true,false,false,false,false,
  false,false,false,true,false,false,false,false,false};
  
  int pot2[5] = 

{palavra[0] ^ palavra[1] ^ palavra[3] ^ palavra[4] ^ palavra[6] ^ palavra[8] ^ palavra[10] ^ palavra[11] ^ palavra[13] ^ palavra[15],
  palavra[0] ^ palavra[2] ^ palavra[3] ^ palavra[5] ^ palavra[6] ^ palavra[9] ^ palavra[10] ^ palavra[12] ^ palavra[13],
  palavra[1] ^ palavra[2] ^ palavra[3] ^ palavra[7] ^ palavra[8] ^ palavra[9] ^ palavra[10] ^ palavra[14] ^ palavra[15],
  palavra[4] ^ palavra[5] ^ palavra[6] ^ palavra[7] ^ palavra[8] ^ palavra[9] ^ palavra[10],
  palavra[11] ^ palavra[12] ^ palavra[13] ^ palavra[14] ^ palavra[15]};
  
  int count = 0;
  int count_aux = 0;
  
  
  for (i = 0; i < 21; i++){

    if (bitcheck[i]){
      
      hamming += (to_string(pot2[count]));
        count++;
    }
    else{

      hamming += (to_string(palavra[count_aux]));
      count_aux++;
      
    }
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


  return 0;
}

