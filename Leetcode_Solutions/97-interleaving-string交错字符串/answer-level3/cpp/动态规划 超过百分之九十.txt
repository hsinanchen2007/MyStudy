### 解题思路
此处撰写解题思路
dp[i][j]表示s1的前i个字符和s2的前j个字符是否和s3的前i+j个字符符合条件。
dp[0][0]=1 都是空时条件成立
初始化dp[0][j],dp[i][0],其实是判断s1和s2的子串是否是s3的前缀。
那么如何求dp[i][j]呢？
此时假设最后一个字符来至s1，那么s1[0~i-1]和s2[0~j]和s3[0~i+j-1]条件成立，且s1[i-1]和s3[i+j-1]相等。如果来至s2，则可类推。
### 代码

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int k = s3.size();
        if(m+n!=k) return false;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] =1;
        int flag = 0;
        for(int i=1;i<m+1;i++)
        {
            if(flag==0&&s1[i-1]==s3[i-1])
            {
                dp[i][0] = 1;
            }
            else 
            {
                flag = 1;//如果出现一个不相同 则后面的都不符合条件
                dp[i][0] = 0;
            }
        }
        flag = 0;
        for(int i=1;i<n+1;i++)
        {
            if(flag==0&&s2[i-1]==s3[i-1])
            {
                dp[0][i] = 1;
            }
            else 
            {
                flag = 1;
                dp[0][i] = 0;
            }
        }
        for(int i=1;i<m+1;i++)
        for(int j=1;j<n+1;j++)
        {
//条件成立时 如果最后一个字符来至s1，则dp[i-1][j] && s1[i-1]==s3[i+j-1]) 如果来至s2，则dp[i][j-1] &&s2[j-1]==s3[i+j-1]
            dp[i][j] = ((dp[i-1][j] && s1[i-1]==s3[i+j-1])||(dp[i][j-1] &&s2[j-1]==s3[i+j-1]) )?1:0; 
        }
        return dp[m][n];

    }
};
```