```
int* drawLine(int length, int w, int x1, int x2, int y, int* returnSize)
{
  int *ret = malloc(sizeof(int) * length);
  memset(ret, 0, sizeof(int) * length);

  int startIndex = y * (w / 32);
  int bitIndexAtY = 0;
  for(int i = startIndex; i < startIndex + length; i++)
  {
    unsigned int n = (unsigned int)1 << 31;

    do{
      if(bitIndexAtY >= x1 && bitIndexAtY <= x2)
        *(ret + i) |= n;

      bitIndexAtY++;
    }while(n = n >> 1);
  }

  *returnSize = length;
  return ret;
}
```
