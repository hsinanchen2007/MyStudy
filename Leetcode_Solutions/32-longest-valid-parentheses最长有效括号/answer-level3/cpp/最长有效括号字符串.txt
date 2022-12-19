### 解题思路
此处撰写解题思路使用动态规划来解决，还是以每个字符结尾时的长度来计算，具体参见代码注释

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        if(!isvalid(s)||s.size()<1)
            return 0;
        vector<int> dp(s.size(),0);//以每一个字符结尾的有效字符长度
        int maxv=0;
        for(int i=1;i<s.size();i++)//i从1开始
        {
            if(s[i]==')')//不需要判断&&i>0
            {
                int pre=i-dp[i-1]-1;//pre直接表示相对应的之前位置，如果i--1位置是左括号，则pre==i-1，不影响判断，所以省略前一个位置是否为左括号的判断
                if(pre>=0&&s[pre]=='(')
                {
                    if(pre>0)
                        dp[i]=dp[i-1]+2+dp[pre-1];
                    else
                        dp[i]=dp[i-1]+2;
                }
            }
            maxv=max(maxv,dp[i]);
        }
        return maxv;
    }
    bool isvalid(string s)
    {
        if(s.size()<1)
            return true;
        int num=0;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]!='(')&&(s[i]!=')'))
                return false;
            
            /*if(s[i]=='(')
                num++;
            else
                num--;
            if(num<0)
                return false;
                */
        }
        return true;
    }
    /*原始繁琐冗余代码
    int longestValidParentheses(string s) {
        if(!isvalid(s)||s.size()<1)
            return 0;
        vector<int> dp(s.size(),0);//以每一个字符结尾的有效字符长度
        int maxv=INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')'&&i>0)
            {
                if(s[i-1]=='(')
                    dp[i]=i==1?2:dp[i-2]+2;
                else
                {
                    int pre=dp[i-1];
                    if(pre>0&&(i-pre-1>=0)&&s[i-pre-1]=='(')
                    {
                        if(i-pre-1>0)
                            dp[i]=dp[i-1]+2+dp[i-pre-1-1];
                        else
                            dp[i]=dp[i-1]+2;
                    }
                }    
            }
            maxv=max(maxv,dp[i]);
        }
        return maxv;
    }
    */
};
```