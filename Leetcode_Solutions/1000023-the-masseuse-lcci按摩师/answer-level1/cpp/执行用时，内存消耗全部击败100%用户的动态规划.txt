### 解题思路
关键是找到动态规划的公式。
因为不能接受相邻的预约，所以当前位置n的时长要么是F[n-1](相邻不添加), 要么是F[n-2]+nums[n](不相邻添加),
即F[n] = max{F[n-1], F[n-2]+nums[n]}，直接在当前数组上计算即可

### 代码

```cpp
class Solution {
public:
    /*
    f(n) = max{f(n-1)+0, f(n-2)+a[n]}
    */
    int massage(vector<int>& nums) 
    {
        if(nums.size()==0)
        {
            return 0;
        }

        if(nums.size()==1)
        {
            return nums[0];
        }

        if(nums.size()==2)
        {
            return max(nums[1],nums[0]);
        }

        //第一第二个位置直接选两个中最大的
        if(nums[1]<nums[0])
        {
            nums[1] = nums[0];
        }

        for(int i=2;i<nums.size();i++)
        {
            if(nums[i-1]<(nums[i-2]+nums[i]))
                nums[i] = nums[i-2]+nums[i];
            else
                nums[i] = nums[i-1];
        }

        return nums[nums.size()-1];
    }
};
```