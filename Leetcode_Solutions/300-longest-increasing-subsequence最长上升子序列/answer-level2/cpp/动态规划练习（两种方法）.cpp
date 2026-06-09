### 方法一解题思路

1. `dp[i]`表示`nums[0]`到`nums[i]`，含`nums[i]`的最长上升子序列；
2. 如果`nums[j] < nums[i]`,就`dp[i]=max(dp[i],dp[j]+1)`
3. 每次保存最大长度`res=max(res,dp[i])`  ////因为最后一个元素`nums[n]`,不一定在最长子序列中
- 
- 如`[10,9,2,5,3,7,101,6]`
- [**10**,9,2,5,3,7,101,6],`dp[0]=1`
- [10,**9**,2,5,3,7,101,6],`dp[1]=1`
- [10,9,**2**,5,3,7,101,6],`dp[2]=1`
- [10,9,**2**,**5**,3,7,101,6],`dp[3]=dp[2]+1`  `//res=2`
- [10,9,**2**,5,**3**,7,101,6],`dp[4]=dp[2]+1`  `//res=2`
- [10,9,2,**5**,3,**7**,101,6],`dp[5]=dp[3]+1`  `//res=3`
- [10,9,2,5,3,**7**,**101**,6],`dp[6]=dp[5]+1`  `//res=4`
- [10,9,2,5,**3**,7,101,**6**],`dp[7]=dp[4]+1`  `//res=4`
- 
- 知`nums[]`最长上升子序列`[2,3/5,7,101]`，最后一个元素6不在序列中

### 代码
```
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return 1;

        vector<int> dp(n,1);
        int res=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
```



### 方法二解题思路

思考@lidada的代码，是另一种思路，效率更高，收获许多，感谢。
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/jin-jie-jie-fa-by-lidada/

思路：
1. 将nums[0]放进容器dp中
2. 当nums[i]大于容器dp中最后一个元素，则将nums[i]放进容器dp中
3. 否则，将容器dp中第一个比nums[i]大的元素换下来，换上nums[i]
4. 虽然容器dp中的元素序列可能并不是按照nums[]中的顺序，说明未替换前的容器dp中的序列为所求
- 如[10,9,2,5,3]
- [10]→[9]→[2]→[2,5]→[3,5];此时[3,5]并非按照[10,9,2,5,3]中的顺序[5,3]
- 说明替换前的[2,5]为所求序列，但两者的长度一样，不影响结果
- 
- 又如[10,9,2,5,3,7,101,18]
- [10]→[9]→[2]→[2,5]→[3,5]→[3,7]→[3,7,101]→[3,7,18]
- 当序列长度达到3时，此时的[3,7,101]是按照nums[]中的顺序，而最后的[3,7,18]则不是按照其顺序
- 说明替换前的[3,7,101]为所求序列，但两者的长度一样，不影响结果
- 
- 只要当突破长度时，是按照顺序的就符合题意

### 代码
```
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return 1;

        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i =1;i<n;++i)
        {
            if(nums[i]>dp[dp.size()-1])
                dp.push_back(nums[i]);
            else
            {
                auto it=lower_bound(dp.begin(),dp.end(),nums[i]);
                *it=nums[i];
            }
        }
        return dp.size();
    }
};
```