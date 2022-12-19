## 思路
### 代码
```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for (int n : nums) {
            if (uset.count(n) > 0) {
                return true;
            } else {
                uset.insert(n);
            }
        }
        return false;
    }
};
```
