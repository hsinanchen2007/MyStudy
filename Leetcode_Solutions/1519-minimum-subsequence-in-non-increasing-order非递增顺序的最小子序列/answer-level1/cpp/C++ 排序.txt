### 解题思路
题目要求的解读：要求的子序列的和大于整个数组和的一半，且是略大于（因为要求长度最小）

题目中要求的"非递增顺序"给了很大的暗示：可以排序，然后从后往前找，找到最短的、和大于整个数组和一半的、子数组即可


### 代码

```cpp
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int aim = 0;
        for(int i = 0; i < nums.size(); i++)
            aim += nums[i];
        aim = aim / 2;
        int sum = 0;
        int idx = nums.size() - 1;
        vector<int> ans;
        while(idx >= 0){
            sum += nums[idx];
            ans.push_back(nums[idx]);
            if(sum > aim)
                return ans;
            idx--;
        }
        return ans;
    }
};
```