// Diego Miranda 2210996 3WA
// Felipe Cancella 2210487 3WA

#include "bigint.h"
#include <stdio.h>

/* Atribuicao (com extensao) */
void big_val(BigInt res, long val) {
  unsigned char* c = (unsigned char*) &val;

  /* Percorre byte a byte (char a char) declarando seu valor */
  for (int i = 0; i < sizeof(long); i++) {
    res[i] = *(c + i);
  }

  /* Verifica se o bit mais significativo do long colocado em res esta ligado ou não. */
  /* if (res[7] & 0x80) then t = 0xff     else t=0x00 */
  unsigned char t = (res[7] & 0x80) ? 0xff : 0x00;

  for (int i = sizeof(long); i < sizeof(BigInt); i++) {
    res[i] = t;
  }
}

/* Operacoes Aritmeticas */

/* res = -a */
void big_comp2(BigInt res, BigInt a) {
  /* Percore byte a byte, ivertendo os bits com a operacao ( X ^ 1 ) */
  for (int i = 0; i < sizeof(BigInt); i++) {
    res[i] = a[i] ^ 0xff;   /* 1 ^ 1 = 0         0 ^ 1 = 1 */

  }

  /* Guarda o 1, a ser acrescentado de acordo com a regra de complemento a dois. (Vai 1) */
  BigInt mais1;

  big_val(mais1, 1);
  big_sum(res, res, mais1);
}

/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b) {
  short sum;
  char vai1 = 0;

  for (int i = 0; i < sizeof(BigInt); i++) {
    sum = a[i] + b[i] + vai1;   /* soma = x + y + (vai-um anterior) */
    res[i] = sum & 0x00ff;      /* guarda o byte(char) menos significativo */
    vai1 = sum >> 8;            /* guarda o vai-um para a proxima soma */
  }
}

/* res = a - b */
void big_sub(BigInt res, BigInt a, BigInt b) {
  BigInt c;
  big_comp2(c, b);      /* transforma o valor em negativo */
  big_sum(res, a, c);   /* soma ao negativo, o mesmo de subtrair */
}

/* res = a * b */
void big_mul(BigInt res, BigInt a, BigInt b) {
  short vai1;  /* armazena o vai-um da multiplicacao */
  int tmp;     /* armazena o resultado "parcial" de cada multiplicacao */

  /* Percorre a cada byte para preencher todo o vetor com 0 */
  for (int i = 0; i < 16; i++) {
    res[i] = 0;
  }

  /* Multiplica cada digito de a com b, somando o resultado parcial ao resultado antigo (res) */
  for (int i = 0; i < 16; i++) {
    vai1 = 0;
    for (int j = 0; j < 16; j++) {
      tmp = a[i] * b[j] + vai1 + res[i + j];  /* a * b + vai1 + resultado parcial armazenado em res[i+j] */
      res[i + j] = (tmp & 0xFF);              /* armazena o byte menos significativo em res[i+j] */
      vai1 = tmp >> 8;                        /* armazena o "resto" (byte mais sign.) em vai1 */
    }
  }
}

/* Operações de Deslocamento */

/* res = a << n */
void big_shl(BigInt res, BigInt a, int n) {
  int byte_diff = n / 8;  /* saber em qual bit do byte será a nova divisão de vetor */
  int bit_diff = n % 8;   /* saber qual a parte do byte anterior a ser colocada no atual */
  short vai1 = 0x00;

  /* Percorre a cada byte para preencher todo o vetor com 0 */
  for (int i = 0; i < 16; i++) {
    res[i] = 0;
  }

  for (int i = 0; i < 16; i++) {
    /* Desloca o byte de a para a esquerda e adiciona o bit mais significativo que fica armazenado na variável vai1.
    Calcula onde guardar esse deslocamento fazendo res[i + byte_diff]. */
    res[i + byte_diff] = (a[i] << bit_diff) | vai1;
    /* Define o vai a 1 como a parte não inserida anteriormente no byte */
    vai1 = (a[i] << bit_diff) >> 8;
  }
}


/* res = a >> n (lógico)*/
void big_shr(BigInt res, BigInt a, int n) {
  int byte_diff = n / 8;     /* saber em qual bit do byte será a nova divisão de vetor */
  int bit_diff = n % 8;      /* saber qual a parte do byte anterior a ser colocada no atual */
  unsigned char vai1 = 0x00; 

  /* Percorre a cada byte para preencher todo o vetor com 0 */
  for (int i = 0; i < 16; i++) {
    res[i] = 0;
  }

  for (int i = 15; i >= byte_diff; i--) {
  /* Desloca o byte de a para a direita e adiciona o bit mais significativo que fica armazenado na variável vai1. Calcula onde guardar esse deslocamento fazendo res[i + byte_diff]. */
  res[i - byte_diff] = (a[i] >> bit_diff) | vai1;
  /* Define o vai a 1 como a parte não inserida anteriormente no byte */
  vai1 = (a[i] << (8 - bit_diff));
  }
}

/* res = a >> n (aritmético)*/
void big_sar(BigInt res, BigInt a, int n) {
  int byte_diff = n / 8;  /* saber em qual bit do byte será a nova divisão de vetor */
  int bit_diff = n % 8;   /* saber qual a parte do byte anterior a ser colocada no atual */ 
  char sig = 0;           /* armazenar o bit mais significativo */
  unsigned char vai1;  
  
  /* Verificar se o bit mais significativo é 1, e alterar se nescessário */
  if (a[15] & 0x80)
    sig = 0xff;

  /* Preencher a cada byte com o bit mais significativo */
  for (int i = 0; i < 16; i++) {
    res[i] = sig;
    vai1 = sig;
  }

  for (int i = 15; i >= byte_diff; i--) {
    /* Desloca o byte de a para a direita e adiciona o bit mais significativo que fica armazenado na variável vai1. Calcula onde guardar esse deslocamento fazendo res[i + byte_diff]. */
    res[i - byte_diff] = (a[i] >> bit_diff) | vai1; 
    /* Define o vai a 1 como a parte não inserida anteriormente no byte */
    vai1 = (a[i] << (8 - bit_diff));
  }
}