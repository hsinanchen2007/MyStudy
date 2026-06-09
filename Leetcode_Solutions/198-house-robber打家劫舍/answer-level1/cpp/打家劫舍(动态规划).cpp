### 解题思路

### 代码

```cpp
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size(),M=0;
        vector<int> dp(n,0);

        for(int i=0;i<n;i++)
        {
            if(i==0 || i==1) dp[i]=nums[i];
            else 
            {
                int temp=0;

                for(int j=0;j<=i-2;j++)
                    if(dp[j]>temp) temp=dp[j];
                
                dp[i]=nums[i]+temp;
            }

            M=max(M,dp[i]);
        }

        return M;
    }
};
```
![image.png](https://pic.leetcode-cn.com/c3d9c55f1c0071a6f0b5f94de54d99842f7d74120aaf3d781de443061d6c481e-image.png)
