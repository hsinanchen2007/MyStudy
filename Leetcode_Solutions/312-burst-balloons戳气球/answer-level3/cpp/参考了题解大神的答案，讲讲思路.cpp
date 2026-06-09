### 解题思路
1. 运用了动态规划的思想
2. dp[i][j]表示的值的意思是把i和j中间的气球全扎破，但是留下i、j所能获得的最大奖金
3. 先是在nums两端补充了边界值1
4. 再3个一组3个一组让相邻三个数相乘，获得最初始的dp[i][i+2]，这相当于只扎破一个气球保留两边的气球所获得的奖金，是一个固定值
5. 再4个一组4个一组地计算dp[i][i+3]，获得这4个气球中间的两个都扎破获得的奖金的最大值
6. 后面把组内元素依次增加，最后获得dp[0][n-1]的值，就是答案
![image.png](https://pic.leetcode-cn.com/b52055d4e52a0ebc1c3fc9c04978b1881a4df13af34965d9a039404175184a0b-image.png)

### 代码

```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        int dp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=0;
            }
        }
        for(int r=2;r<n;r++)
        {
            for(int i=0;i<n-r;i++)
            {
                int j=i+r;
                for(int k=i+1;k<j;k++)
                {
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
```