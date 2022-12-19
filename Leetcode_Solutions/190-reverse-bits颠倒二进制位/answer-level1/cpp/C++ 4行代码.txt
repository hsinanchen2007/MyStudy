```
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i=0;i<32;i++)
            if((n&(uint32_t)pow(2, i))>0) res += pow(2, 31-i);
        return res;
    }
};
```
