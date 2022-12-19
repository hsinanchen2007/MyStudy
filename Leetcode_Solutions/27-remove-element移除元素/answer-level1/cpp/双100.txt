![捕获.PNG](https://pic.leetcode-cn.com/650b3de1a6380cef41ec793fc8474083950137caa46a401a874a0537f955e789-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = nums.size();
        for (auto i = nums.begin(); i < nums.end(); ++i) {
            if (*i == val) {
                i = nums.erase(i);
                --res;
                --i;
            }
        }
        return res;
    }
};
```