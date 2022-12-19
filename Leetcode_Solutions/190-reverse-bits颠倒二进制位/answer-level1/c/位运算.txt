```
uint32_t reverseBits(uint32_t n) {
    uint32_t temp = 0;
    uint32_t res  =0;
    for(int i=0; i < 32; i++) {
        temp   = n & 1;
        res   |= temp;
        if(i<31){
            n  >>= 1;
            res  <<= 1 ;
        }
    }
    return res;

}
```