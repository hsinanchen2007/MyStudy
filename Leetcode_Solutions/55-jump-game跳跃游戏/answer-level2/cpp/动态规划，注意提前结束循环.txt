跳跃游戏->青蛙爬台阶问题->斐波拉切问题->动态规划
呦西，开搞！
利用max_range存储到i号元素为止，能跳跃到的最大位置。
更新公式为：
max_range[i]=max(max_range[i-1],i+nums[i]), if max_range[i-1]>=i (i号元素可达)
注意i号元素不可达时，提前break; (max_range[i]>=n-1)时提前 return； n=1直接返回true；
时间复杂度O(n)，空间复杂度O(n)(应该可以优化为O(1));
```
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        return true;
        vector<int>max_range(n,nums[0]);
        for(int i=1;i<n;++i)
        {
            if(max_range[i-1]>=i)
            {
                max_range[i]=max(max_range[i-1],i+nums[i]);
                if(max_range[i]>=n-1)
                return true;
            }
            else
            break;
        }
        return false;
        
    }
};
```
