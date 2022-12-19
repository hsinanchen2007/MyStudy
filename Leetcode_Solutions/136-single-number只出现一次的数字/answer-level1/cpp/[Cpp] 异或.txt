### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto it : nums) res ^= it;
        return res;
    }
};
```