**位运算，<<CS:APP>>第二章有许多位运算的知识。**
```c
uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for(int i = 0; i < 32; i++){
        ans <<= 1;
        ans += (n & 1);
        n >>= 1;
    }
    return ans;
}
```