单指针遍历，若遇到1，flag + 1, 遇到0，判断此时flag是否大于ans记录的个数，若是，令ans = flag，且让flag初始化。 若否，只让flag初始化。最终剩下的ans就是最大连续1的个数。

其实代码比解释清楚，看代码就好。😁
```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int flag = 0; //记录每次连续1的个数
        int ans = 0; //记录最大连续1的个数
        for(int i = 0; i < nums.size(); ++ i)
        {
            if(nums[i] == 1)
            {
                ++flag;
            }
            else
            {
                if(ans < flag)
                {
                    ans = flag;
                    flag = 0;
                }
                else
                    flag = 0;
            }
        }
        if(ans < flag)
            ans = flag;
        return ans;
    }
};
```