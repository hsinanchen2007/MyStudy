```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0,num=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                num++;
            else
                num=0;
            max>num?:max=num;
        }
        return max;
    }
};
```



![2I}BJ8`@(GL3Y$78RGHFMJE.png](https://pic.leetcode-cn.com/4e7017cf90a558a3bc43e6bae1f791193d6a0a45da4e7b85df33e0e205ee369f-2I%7DBJ8%60@\(GL3Y$78RGHFMJE.png)
