```
int hammingWeight(uint32_t n) {
    int i = 0;
    uint32_t m = 1;
    while(n)
    {
        if(n&m)
        {
            i++;    
        }
        n >>= 1;
    }
    return i;
}
int hammingWeight(uint32_t n) {
    int i = 0;
    while(n)
    {
        n &= n-1;
        i++;
    }
    return i;
}
```
