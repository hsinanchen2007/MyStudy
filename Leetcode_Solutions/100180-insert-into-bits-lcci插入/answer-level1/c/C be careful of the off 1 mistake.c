```
int insertBits(int N, int M, int i, int j){

  // get bits mask from i to j
  int mask = (((unsigned long)1 << (j + 1)) - 1) - (((unsigned int)1 << i) - 1);

  // left shift M to align bit 0 to bit i
  M <<= i;

  return (N & ~mask) | (M & mask);
}
```
