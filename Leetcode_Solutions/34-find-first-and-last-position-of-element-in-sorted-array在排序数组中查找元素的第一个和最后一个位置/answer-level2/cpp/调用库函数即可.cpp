### 解题思路
lower_bound找到大于等于指定值的第一个位置，upper_bound找到大于指定值的第一个位置，那么lower_bound可以用来找最左边的，upper_bound的前一个就是最右边的。

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return vector<int>{-1, -1};
        vector<int> ans;
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(first == nums.size() || nums[first] != target)
            ans.push_back(-1);
        else
            ans.push_back(first);
        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(last == 0 || nums[last - 1] != target)
            ans.push_back(-1);
        else
            ans.push_back(last - 1);
        return ans;
    }
};
```