#### 核心思想
三行实现逆置操作，手动实现32次循环，而不是用n操作，n是32位无符号二进制数


```
uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        uint32_t pop = 0;
        for(int i=0;i<32;++i){
            pop=n%2;
            n=n/2;
            ret=ret*2+pop;
        }
        return ret;
    }
```
