### 解题思路
逐位生成

### 代码

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0, power = 31;
        while(n != 0){
            ans += (n & 1) << power;
            n >>= 1;
            power --;
        }
        return ans;
    }
};
```