环形-->首和尾不可共存，相当于拆分成两段，0~n-1和1~n-2，求较大值即可
动态规划：
```
代码块class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        int num1 = 0, num2 = 0,max_sum = 0,max_sum2 = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            max_sum = max(num1 + nums[i], num2);
            num1 = num2;
            num2 = max_sum;
        }
        num1 = 0, num2 = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            max_sum2 = max(num1 + nums[i], num2);
            num1 = num2;
            num2 = max_sum2;
        }
        return max(max_sum, max_sum2);
    }
};
```
