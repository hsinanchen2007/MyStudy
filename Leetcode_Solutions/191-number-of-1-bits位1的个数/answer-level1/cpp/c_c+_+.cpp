### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
            n = n - (n & -n);
            ++ans;
        }
        return ans;
    }
};
```