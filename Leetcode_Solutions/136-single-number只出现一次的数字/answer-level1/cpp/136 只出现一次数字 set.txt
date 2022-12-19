### 解题思路
使用了额外的空间，用set记录是否曾经出现
### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> m;
        for (auto i : nums) {
            if (m.find(i) == m.end()) m.insert(i);
            else m.erase(i);
        }
        return *(m.begin());
    }
};
```