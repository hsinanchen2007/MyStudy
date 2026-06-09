```
int convertInteger(int A, int B){

  int count = 0;

  for(unsigned int xor = A ^ B; xor != 0; xor = xor & (xor - 1))
    count++;

  return count;
}
```
