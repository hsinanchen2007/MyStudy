```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        uint32_t factor = 0x01;
        while(n>0)
        {
            if(n&factor) 
            {
                result++;
                n ^= factor;
            }
            factor = factor<<1;
        }
        return result;
    }
};
```
