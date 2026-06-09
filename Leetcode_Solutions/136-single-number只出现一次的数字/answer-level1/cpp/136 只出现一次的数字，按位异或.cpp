### 解题思路
按位异或
### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto i : nums) {
            res ^= i;
        }
        return res;
    }
};
```