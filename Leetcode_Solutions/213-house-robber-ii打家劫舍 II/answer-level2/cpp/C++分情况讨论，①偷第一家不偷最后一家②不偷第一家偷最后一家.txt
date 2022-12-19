```
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(!size) return 0;
        if(size == 1)   return nums[0];
        if(size == 2)   return max(nums[0], nums[1]);
        int m1 = max(nums[0], nums[1]), m2 = max(nums[1], nums[size-1]);
        vector<int> dp1(size+1), dp2(size+1);
        dp1[0] = nums[1], dp1[1] = max(nums[1], nums[2]), dp2[0] = nums[0], dp2[1] = max(nums[0], nums[1]);
        for(int i = 2; i < size-1; i++){
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i]);
            m1 = m1 > dp2[i] ? m1 : dp2[i];
        }
        for(int i = 3; i < size; i++){
            dp1[i-1] = max(dp1[i-2], dp1[i-3] + nums[i]);
            m2 = m2 > dp1[i-1] ? m2 : dp1[i-1];
        }
        return max(m1, m2);
    }
};
```
