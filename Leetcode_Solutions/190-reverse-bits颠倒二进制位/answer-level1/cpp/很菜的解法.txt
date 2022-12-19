### 解题思路
菜的不要不要的解法

### 代码

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;i++){
            res+=(n%2)<<(31-i);
            n/=2;
        }
        return res;
    }
};
```