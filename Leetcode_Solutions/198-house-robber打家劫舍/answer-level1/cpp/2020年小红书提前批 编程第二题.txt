笔试题稍微有些不一样，还要返回抢了几家，就是dp2
```
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int numslen = nums.size();
        
        if(numslen==0) return 0;
        if(numslen==1) return nums[0];
        
        vector<int> dp1(numslen,0);
        vector<int> dp2(numslen,1);                            //这个数组用来存采用的数组下标。
        dp1[0] = nums[0]; dp1[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<numslen;i++)
        {
            if(nums[i]+dp1[i-2]>dp1[i-1])
            {
                dp1[i] = nums[i]+dp1[i-2];
                dp2[i] = dp2[i] + dp2[i-2];
            }
            else 
            {
                dp1[i] = dp1[i-1];
                dp2[i] = dp2[i-1];
            }
        }
        cout<<dp2[numslen-1];
        return dp1[numslen-1];
    }
};
```
