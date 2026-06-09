动态规划，打家劫舍问题翻版而已。
```
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> res(nums.size(),0) ;
        res[0] = nums[0];
        res[1] = max(nums[0],nums[1]);
        for(int i = 2; i<nums.size(); i++){
             res[i] = (max(res[i-2]+nums[i], res[i-1]));
        }
        return res[nums.size()-1];
    }
};
```