### 解题思路
参考大佬的做法，类似找最长回文子串，但是要累加，采用动态规划区间dp。

### 代码

```cpp
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int dp[101][101];
        for(int i=0;i<arr.size();++i)
        {
            dp[i][i]=1;                       //先将单独一个都标记为一步
        }
        for(int i=0;i<arr.size()-1;++i)            //此处循环因为计算相邻，应终止在arr长度-1处
        {
            if(arr[i]==arr[i+1]) dp[i][i+1]=1;                //相邻相等则为一步，不等需要两步
            else dp[i][i+1]=2;
        }
        for(int len=3;len<=arr.size();++len)
        {
            for(int i=0;i<arr.size()-len+1;++i)
            {
                if(arr[i]==arr[i+len-1]) dp[i][i+len-1]=dp[i+1][i+len-2];       //两端相等时，需要的步数与各缩进一个数字时需要的步数相同
                else
                {
                    dp[i][i+len-1]=len;                     //先设置为每个数字均需要一步
                    for(int j=0;j<(len-1);++j)
                    {
                        if(dp[i][i+len-1]>dp[i][i+j]+dp[i+j+1][i+len-1])
                        dp[i][i+len-1]=dp[i][i+j]+dp[i+j+1][i+len-1];     //选取区间内步数和最小的组合，注意a-c可以分为a-b,b+1-c
                    }
                }
            }
        }
        return dp[0][arr.size()-1];       //返回从第一个数字到最后一个数字的最小步数和
    }
};
```