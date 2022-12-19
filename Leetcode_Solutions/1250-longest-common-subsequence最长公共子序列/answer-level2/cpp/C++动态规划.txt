### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/72a1c6557bb01f2e1e172fd5a62e4af512e81ceeee3b5fa98d49b0bfb4e90cba-image.png)
![image.png](https://pic.leetcode-cn.com/158764058e6b6f47eccf9f65f772f070d42f6b06d4ba792f2ae598d70e59b9bb-image.png)
![image.png](https://pic.leetcode-cn.com/5887fcbdf2078089b56a06b35dbc82c40add1f1f7b17c1f0bbcf66d31e2fdfad-image.png)
![image.png](https://pic.leetcode-cn.com/474a09154cf052dd5b38cda17acd192fa3a28cf7f296264d0e26ef5bc90bc007-image.png)
### 代码

```cpp
class Solution {
public:
    /*简单的递归写法，但超时，得用动态规划
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
    int len2 = text2.length();
    char s1[50] = {0}, s2[50] = {0};
    
    if (len1 == 0 || len2 == 0)
        return 0;
    else if (text1[len1 - 1] == text2[len2 - 1]) {
        text1.copy(s1, len1 - 1);
        if (len1 - 1 == 0)
            s1[0] = 0;
        //cout << "s1:" << s1 << endl;
        text2.copy(s2, len2 - 1);
        if (len2 - 1 == 0)
            s2[0] = 0;
       // cout << "s2:" << s2 << endl;
        return longestCommonSubsequence(s1, s2) + 1;
    } else {
        text1.copy(s1, len1 - 1);
        if (len1 - 1 == 0)
            s1[0] = 0;
        text2.copy(s2, len2 - 1);
        if (len2 - 1 == 0)
            s2[0] = 0;
        return max(longestCommonSubsequence(text1, s2),
                   longestCommonSubsequence(s1, text2));
    }
    }*/
    int longestCommonSubsequence(string X,string Y)
    {
        int m=X.length();
        int n=Y.length();
        int c[m+1][n+1];
        for(int i=0;i<=m;++i)//第一列全为0，表示Y为空，是LCS为0
        {
            c[i][0]=0;
        }
        for(int j=0;j<=n;++j)//第一行全为0，表示X为空时，LCS为0
        {
            c[0][j]=0;
        }
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(X[i-1]==Y[j-1])//注意这里，把矩阵画出来就清楚了，
                {
                    c[i][j]=c[i-1][j-1]+1;
                }
                else if(c[i-1][j]>=c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                }
                else
                {
                    c[i][j]=c[i][j-1];
                }
            }
        }
        return c[m][n];
    }
};
```