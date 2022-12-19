### 解题思路
用动规还是蛮简单的这题。。

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word2.length()+1,0);
        for(int i=0;i<dp.size();i++)
        {
            dp[i]=i;    //初始化第一行
        }
        for(int i=1;i<=word1.size();i++)
        {
            int value_dp=dp[0];  //保存左上角的值
            dp[0]=i;    //初始化第一列

            for(int j=1;j<=word2.size();j++)
            {
                int temp_dp=value_dp;  //因为需要刷新value，所以还需要一个临时变量保存value的值
                value_dp=dp[j];  //刷新value_dp的值

                /**
                 *  如果字母相等，无需任何操作，直接赋值temp即可。如果不相等，找到操作次数最少的上一步操作并增加一步
                 */       
                word1[i-1]==word2[j-1]?dp[j]=temp_dp:dp[j]=(std::min(std::min(temp_dp,dp[j-1]),dp[j])+1);
            }

        }
        return dp.back();
    }
};
```