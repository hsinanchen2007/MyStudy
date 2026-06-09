### 解题思路
简单

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        unordered_map<int, int> mp;
        for (auto n : nums)
            mp[n]++;
        for (auto n : nums)
            if (mp[n] == 1)
                return n;
        return 0;
    }
};
```