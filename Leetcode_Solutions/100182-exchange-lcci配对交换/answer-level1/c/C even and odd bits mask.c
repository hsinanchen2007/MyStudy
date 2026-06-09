```
#define EVEN_BIT_MASK 0x55555555
#define ODD_BIT_MASK 0xAAAAAAAA

int exchangeBits(int num){
  return ((EVEN_BIT_MASK & num) << 1) | ((ODD_BIT_MASK & num) >> 1);
}
```
