1. 令左括号（ = 1  ， 右括号） = -1
2. 括号序列合法==>从start位置开始的所有前缀和cnt>=0,最长的有效括号时前缀和cnt=0
3. 遍历所有括号，
    1）：当cnt>=0时，继续遍历；
    2）：当cnt<0时，令start=i+1，cnt=0；
    3）：当cnt==0时，从start到i就是有效的括号序列。
4. 为了避免左括号数量多于右括号数量的情况（即((((()))）将括号序列翻转一遍，并将左括号转为右括号，右括号转为左括号（转为((()))))）,再调用函数统计有效括号。

```
class Solution {
public:
    int work(string s)
    {
        int res=0;
        for(int i=0,cnt=0,start=0;i<s.size();i++)
        {
            if(s[i]=='(')cnt++;
            else
            {
                cnt--;
                if(cnt < 0)start=i+1,cnt=0;
                else if(cnt==0)res=max(res,i-start+1);
            }
        }
        return res;
    }
    
    int longestValidParentheses(string s) {
        int res;
        res=work(s);
        reverse(s.begin(),s.end());
        for(auto &a:s)a^=1; //左括号转为右括号，右括号转为左括号
        res=max(res,work(s));
        return res;
    }
};
```
