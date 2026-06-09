- 直接看代码，很好理解的

```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        
        while(n) {
            res += n & 1;
            n >>= 1;
        }
        
        return res;
    }
};
```
