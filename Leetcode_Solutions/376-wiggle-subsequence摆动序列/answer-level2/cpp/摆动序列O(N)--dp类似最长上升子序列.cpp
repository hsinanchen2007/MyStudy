### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/65dc758779c5f562b0dc8078bd4fb36329aa2530b5b36fb67291ee2d4f121786-%E6%8D%95%E8%8E%B7.PNG)

+ 先证明，对于任意序列的最长摆动序列，第一个元素一定包含在内。
+ dp[i]表示当前长度为i的第i个数为dp[i];
+ 对任意序列，我们分为两个过程，一定可以找到（相应的dp数组应为2维）；
+ 第一个过程：dp[1] = nums[0];找dp[2],dp[2]>dp[1];,找dp[3],dp[3]<dp[2]...显然，找dp[i]是否大于或者小于dp[i-1]与当前需要的位置i的奇偶有关。如dp[2]需要大于前一个数，dp[3]需要小于前一个数。    当扫描nums数组时，若nums[i]满足条件 ,则纳入dp数组，dp数组计数位置+1，否则应该替换掉前一个位置。
  如  1 5 6 8 7；   dp[1] = 1,dp[2] = 5；因为此时6大于5不满足条件，但由于dp[3]需要小于dp[2],显然   dp[2]越大，作用越大，因此6比5能发挥更大的作用，替换。

+ 第二个过程，dp[2]<dp[1]...


+ dp数组为2维，代表以nums[0]开始的两种摆动基调。

很难说清楚，但代码很好懂，很对称

### 代码

```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<vector<int>>dp(2,vector<int>(nums.size()+1,0));
        //dp[i]表示长度为i的递增子序列的第i个元素
        dp[0][1] =  dp[1][1]= nums[0];//初始化
        int cnt = 2;//将要填入的下一个位置
        int cnt1 = 2;
        for(int i=1;i<nums.size();i++)
        {
            //先计算递增
            if(cnt%2==0)
            {
                //找比上一个大的
                if(nums[i]>dp[0][cnt-1])
                {
                    dp[0][cnt++] = nums[i];
                }
                else
                {
                    //找插入位置,说明该点能发挥更大的作用
                    dp[0][cnt-1] = nums[i]; 
                }
            }
            else
            {
                //找比起小的
                if(nums[i]<dp[0][cnt-1])
                    dp[0][cnt++] = nums[i];
                else
                    dp[0][cnt-1] = nums[i];
                
               
            }

            //再计算递减
            if(cnt1%2==0)
            {
                
                 if(nums[i]<dp[1][cnt1-1])
                    dp[1][cnt1++] = nums[i];
                else
                    dp[1][cnt1-1] = nums[i];
            }
            else
            {
                 if(nums[i]>dp[1][cnt1-1])
                {
                    dp[1][cnt1++] = nums[i];
                }
                else
                {
                    //找插入位置,说明该点能发挥更大的作用
                    dp[1][cnt1-1] = nums[i]; 
                }
            }
        }
       return max(cnt,cnt1)-1;
    }
};
```