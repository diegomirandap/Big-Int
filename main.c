
#include "bigint.h"
#include <stdio.h>
/*
#define NUM_BITS 128

void imprime(BigInt res);

int main(void) {

  BigInt Valor1, Valor2, Valor3, Valor4, Valor5, Valor6, Valor7, Valor8, Valor9,
      Valor10, Valor11, Valor12, Valor13, Valor14, Valor15, Valor16, Valor17,
      Valor18, Valor19, Valor20, Valor21, TESTE, TESTE2;
  long val1 = 1;
  long val2 = -2;
  long val3 = 1792;
  long val4 = -500;
  long val5 = 9223372036854775807;
  long val6 = 116193;

  big_val(Valor1, val1);
  imprime(Valor1);
  printf(" : 1\n\n");
  big_val(Valor2, val2);
  imprime(Valor2);
  printf(" : -2\n\n");
  big_val(Valor3, val3);
  imprime(Valor3);
  printf(" : 1792\n\n");
  big_val(Valor4, val4);
  imprime(Valor4);
  printf(" : -500\n\n");
  big_val(Valor10, val5);
  imprime(Valor10);
  printf(" : 9223372036854775807\n\n");
  big_val(Valor16, val6);
  imprime(Valor16);
  printf(" : 116193 \n\n");

  // big_val(Valor5, val4);

  printf("\n\n\n");

  big_comp2(Valor6, Valor1); // 1 --> -1
  imprime(Valor6);
  printf(" : -1 \n\n");
  big_comp2(Valor9, Valor2); // -2 --> 2
  imprime(Valor9);
  printf(" : 2 \n\n");
  big_comp2(Valor11, Valor3); // 1792 --> -1792
  imprime(Valor11);
  printf(" : -1792 \n\n");
  big_comp2(Valor12, Valor4); // -500 --> 500
  imprime(Valor12);
  printf(" : 500 \n\n");

  big_sum(Valor7, Valor10, Valor10); //9223372036854775807 + 9223372036854775807
  imprime(Valor7);
  printf(" : 922... + 922...\n\n");
  big_sum(Valor8, Valor1, Valor2); // 1+(-2)
  imprime(Valor8);
  printf(" : 1 + (-2)\n\n");
  big_sub(Valor13, Valor9, Valor1); // 2-1
  imprime(Valor13);
  printf(" : 2 - 1\n\n");
  big_sub(Valor14, Valor1, Valor9); // 1-2
  imprime(Valor14);
  printf(" : 1 - 2\n\n");
  big_sub(Valor15, Valor1, Valor2); // 1-(-2)
  imprime(Valor15);
  printf(" : 1 - (-2)\n\n");
  printf("\n\n\n");

  big_shl(Valor17, Valor16, 11);
  imprime(Valor17);

  printf(" : 116193 << 11 = 237963264 (lógico)\n\n");

  big_shr(Valor18, Valor17, 11);
  imprime(Valor18);

  printf(" : 237963264 >> 11 = 116193 (lógico)\n\n");

  big_sar(Valor19, Valor2, 1);
  imprime(Valor19);

  printf(" : -2 >> 1 (aritmético)\n\n");
  big_sum(Valor20, Valor1, Valor2);
  imprime(Valor20);

  printf("\n\n----\n");
  big_mul(Valor21, Valor1, Valor2);
  imprime(Valor21);

}
 
void imprime(BigInt res) {
  for (int i = 0; i < sizeof(BigInt); i++) {
    printf("%02x ", res[i]);
  }
  printf("  : BigInt\n");
  for (int i = sizeof(BigInt)-1; i >= 0; i--) {
    printf("%02x ", res[i]);
  }
}*/