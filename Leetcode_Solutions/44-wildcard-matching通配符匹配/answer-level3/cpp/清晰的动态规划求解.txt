### 解题思路
对于动态规划的基本操作，一般都是要有一个表格去记录我们求解的过程，本题也是这样求解，用一个二维数组dp[i][j]来记录每一步的情况，本题解中的二维数组多初始化一行一列，便于解决边界问题,在比较两个字符的过程中遇到p[i]='*',或p[i]=s[j] 或p[i]='?'的情况时，为了便于理解将在下面的代码中进行分析时。下面给出了两个例子如下：
1.s="adceb"  p="*a*b"  true
![image.png](https://pic.leetcode-cn.com/6f20b3a6315d7b3c6970708dcba63d659349e9aab5ddc6a62dcd89900abe0b04-image.png)


2.s="bbcdcb" p="a*c?b"  false
![image.png](https://pic.leetcode-cn.com/8968be1493572f9ebc7f025b4a4d187d6da55cf3555073e5f9fb2f523effafaf-image.png)


### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
      if(s.empty()&&p.empty())
      {
          return true;
      }
       if(p.empty())
       {
           return false;
       }
       vector<vector<bool>>dp(p.length()+1,vector<bool>(s.length()+1,false));//多初始化一行一列，并初始化未false
       dp[0][0]=true;//将第一个初始化未true.
        int flag=0;
        for(int i=1;i<=p.length();i++)
        {
            flag=0;
            for(int j=0;j<=s.length();j++)
            {
                if(j==0) //这个if判断是分析当s为空p不空的情况的
                {
                    if(p[i-1]!='*')
                    {
                        dp[i][j]=false;
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
                else  //当p 和 s都不为空时
                {
                    if(p[i-1]=='*')  
                    {
                        if(dp[i-1][j]==false&&flag==0&&i!=1) //当p[i-1]为'*'时要判断它的上一行出现第一个 true 是在那一列，然后在那一列之后的dp[i][j]
                                //都设为true,用flag做标记。因为只有在dp[i-1][j]为true的时候才表示截至到p[i-1]，s[j]的字符都已匹配好了，这时候'*'才能和                              // 后面的匹配上，否则前面的都没匹配好‘*’也是无法匹配成功的。(由于边界问题这里排除第一行，具体原因可以看看上面的表格思考一下)
                        {
                            dp[i][j]=false;
                            continue;
                        }
                        flag=1;
                        dp[i][j]=true;
                    }
                    else if(p[i-1]=='?')//当p[i-1]=‘?’的时候?可以和任何一个字符匹配也就和p[i-1]=s[j]的时候判断情况一样了。
                    {
                         dp[i][j]=dp[i-1][j-1];
                    }
                    else
                    {
                        if(p[i-1]==s[j-1])
                        {
                            dp[i][j]=dp[i-1][j-1];
                        }
                        else
                        {
                             dp[i][j]=false;
                        }
                    }
                }
            }
            if(p[i-1]=='*'&&flag==0&&i!=1)
            {
                return false;
            }
        }
        return dp[p.length()][s.length()];
    }
};
```