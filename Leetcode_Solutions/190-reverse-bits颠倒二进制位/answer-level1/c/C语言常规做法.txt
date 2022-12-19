```c
uint32_t reverseBits(uint32_t n) {
    unsigned long num=0;
    int i;
    for(i=0;i<32;i++){
        num=num*2+n%2;
        n=n/2;
    }
    return num;
}
```