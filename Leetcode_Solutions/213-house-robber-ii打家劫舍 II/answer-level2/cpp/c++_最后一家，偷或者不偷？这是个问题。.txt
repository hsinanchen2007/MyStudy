```
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];

        //不偷最后一家，从第一家开始
        int* dp1 = (int*)calloc(3, sizeof(int));
        if (len >= 2)
            dp1[0] = nums[0];
        if (len >= 3)
            dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len - 1; i++)
            dp1[i % 3] = max(dp1[(i - 2) % 3] + nums[i], dp1[(i - 1) % 3]);

        //偷最后一家，从第二家开始
        int* dp2 = (int*)calloc(3, sizeof(int));
         if (len >= 2)
            dp2[0] = nums[1];
        if (len >= 3)
            dp2[1] = max(nums[1], nums[2]);
        for (int i = 3; i < len; i++)
            dp2[(i - 1) % 3] = max(dp2[(i - 3) % 3] + nums[i], dp2[(i - 2) % 3]);

        //返回两种偷法的最大值
        return max(dp1[(len - 2) % 3], dp2[(len - 2) % 3]);
    }
};
```
