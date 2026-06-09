### 解题思路
此处撰写解题思路
哈哈，暴力DFS居然通过了，之前做过k个子集和的问题，当时用的回溯算法加剪枝过的，这里突然感觉回溯似乎看起来不太简洁，嗯，直接上dfs吧。因为递归做了大量的重复计算，时间复杂度大概是2^n。。。这是显然过不了的。。。so这里用了两个重要的剪枝，1：筛选掉target=0的情况 2：对数组逆序排列，然后筛选掉最大值超过和的一半的情况，嗯大概就这些。
### 代码

```cpp
class Solution {
public:
    bool DFS(int target,vector<int>& nums,int j)
    {
        if(target==0)
            return true;
        if(j==nums.size())
            return false;
        if(target<0)
            return false;
        return DFS(target-nums[j],nums,j+1)||DFS(target,nums,j+1);
    }
    bool canPartition(vector<int>& nums) {
         int sum=accumulate(nums.begin(),nums.end(),0);
         sort(nums.rbegin(),nums.rend());
         int target=sum/2;
         if(sum%2==1)
             return false;
         if(nums[0]>target)
             return false;
         if(nums[0]==target)
             return true;
         return DFS(target,nums,0);
    }
};
```