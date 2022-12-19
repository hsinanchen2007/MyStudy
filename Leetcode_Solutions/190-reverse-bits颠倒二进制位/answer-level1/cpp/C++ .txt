### 解题思路
获取到n的最后一位将其移动到最高位,每次n都要右移一位将最后一个数清除 最后将结果加起来 移动位数也要减一

### 代码

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int bitSize =31;n!=0;n>>=1,bitSize--){
            ans +=(n&1)<<bitSize;
        }
        return ans;
    }
};
```