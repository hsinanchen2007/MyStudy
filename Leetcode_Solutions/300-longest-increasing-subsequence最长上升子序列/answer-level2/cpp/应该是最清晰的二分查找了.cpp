主要是改变了dp数组的定义
```cpp
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0)
        {
            return 0;
        }
        vector<int> dp;         //dp[i]表示长度为i+1的上升子序列最后一位的最小值
        dp.push_back(nums[0]);      //push一个初始值
        for(auto num: nums)
        {
            /*比最长序列最后一位大，序列长度+1*/
            if(num > dp[dp.size() - 1])
            {
                dp.push_back(num);
            }
            else
            {
                /*二分查找，找到dp[i-1] < num < dp[i]的位置*/
                int left = 0, right = dp.size() - 1;
                while(left < right)
                {
                    int mid = (left + right)/2;
                    if(num > dp[mid])
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid;
                    }
                }
                dp[left] = num;     //更新这个序列最后一位的值
            }
        }
        return dp.size();       //dp数组的长度即为最长上升子序列的长度
    }
};
```