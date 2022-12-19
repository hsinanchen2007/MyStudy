不知道为什么这道题目被设置成困难了，但是思路真的很简单，而且时间复杂度和空间复杂度也很低，思路见源码

```
class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        if(nums.size()<2) return 0;
        sort(nums.begin(),nums.end());
        int max_num=0;
        for(int i=1;i<nums.size();i++)
        {
            int temp=nums[i]-nums[i-1];
            max_num=max(max_num,temp);
        }
        return max_num;
    }
};
```
