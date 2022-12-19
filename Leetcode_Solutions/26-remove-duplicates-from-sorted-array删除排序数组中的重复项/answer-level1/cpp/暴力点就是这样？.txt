### 解题思路
此处撰写解题思路
暴力点就是这样？
### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.end()-nums.begin();
    }
};
```