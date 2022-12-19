### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::set<int> ss;
        for (auto i : nums) {
            if (ss.find(i) != ss.end()) return i;
            ss.insert(i);
        }
        return -1;
    }
};
```