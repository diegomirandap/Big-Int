// Diego Miranda 2210996 3WA
// Felipe Cancella 2210487 3WA
#define NUM_BITS 128

/* Cria um "tipo" vetor de 16 bytes (128 bits). Cada byte eh um char */
typedef unsigned char BigInt[NUM_BITS / 8];

/* Atribuicao (com extensao) */
void big_val(BigInt res, long val);

/* Operacoes Aritmeticas */

/* res = -a */
void big_comp2(BigInt res, BigInt a);

/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b);

/* res = a - b */
void big_sub(BigInt res, BigInt a, BigInt b);

/* res = a * b */
void big_mul(BigInt res, BigInt a, BigInt b);

/* Operacoes de Deslocamento */

/* res = a << n */
void big_shl(BigInt res, BigInt a, int n);

/* res = a >> n (logico)*/
void big_shr(BigInt res, BigInt a, int n);

/* res = a >> n (aritmetico)*/
void big_sar(BigInt res, BigInt a, int n);