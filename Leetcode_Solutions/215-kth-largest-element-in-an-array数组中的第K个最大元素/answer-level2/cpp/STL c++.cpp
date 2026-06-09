### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty())
            return {};
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];
    }
};
```