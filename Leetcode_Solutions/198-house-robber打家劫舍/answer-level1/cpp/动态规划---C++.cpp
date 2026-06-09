```
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        if(nums.empty())  //空则返回0
            return 0;
        int num1 = 0, num2 = 0, max_sum;
        for(int i = 0; i < nums.size(); i++)   //计算出打劫到每个房屋时的最大值，动态叠加到最后一个房屋，即为最终的最大值
        {
            max_sum = max(num1 + nums[i], num2);
            num1 = num2;
            num2 = max_sum;
        }
        return max_sum;
    }
};
```
