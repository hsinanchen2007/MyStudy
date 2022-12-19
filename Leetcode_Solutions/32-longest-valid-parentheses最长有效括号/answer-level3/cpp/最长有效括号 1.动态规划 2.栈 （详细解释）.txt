

动态规划思路：创建动态规划数组dp[n],dp[i]为以index=i为结尾的最大有效括号范围，所以凡是s[i]=='('，肯定不能作为结尾,dp[i]=0,如果s[i]==')',有可能作为结尾,接下来分为两种情况，情况一:s[i-1]=='(',则dp[i]=dp[i-2]+2,情况二:如果s[i-1]==')',则举例子  -()()),我们假设-是一个括号，是左括号还是右括号未知,dp[i-1]==dp[4]==4,dp[5]其实是取决于dp[0]也就是 - 究竟是左括号还是右括号,假设dp[0] 也就是- 是左括号，那么dp[0]和dp[5]配对。

FROM XUEBI-IFCEN If this solution can help you, please click 'smile'

```
class Solution {
public:
    int longestValidParentheses(string s) {
        //创建动态规划数组dp[n],dp[i]为以index=i为结尾的最大有效括号范围，所以凡是s[i]=='('，肯定不能作为结    
        //尾,dp[i]=0,如果s[i]==')',有可能作为结尾,接下来分为两种情况，情况一 s[i-1]=='(',则dp[i]=dp[i-2]+2,情况         //二如果s[i-1]==')',则举例子  -()()),我们假设-是一个括号，是左括号还是右括号未知,dp[i-1]==dp[4]==4,
        //dp[5]其实是取决于dp[0]也就是 - 究竟是左括号还是右括号,假设dp[0] 也就是- 是左括号，那么dp[0]和dp[5]配对
        //dp[i]=dp[i-1]+2 相当于dp[5]=dp[4]+2。当然如果-左边还有括号，那么需要dp[i]需要加上紧贴着-左边的那个元素         //的dp值
        int n=s.size();
        if(n<=1) return 0;
        int dp[n]={0};
        if(s[0]=='('&&s[1]==')')
        {
            dp[0]=0; dp[1]=2;
        }
        else
        {
            dp[0]=0; dp[1]=0;
        }
        for(int i=2;i<n;i++)
        {
            if(s[i]=='(')//'('不可能作为结尾
                dp[i]=0;
            else//说明s[i]==')'
            {
                if(s[i-1]=='(')
                    dp[i]=dp[i-2]+2;
                else//s[i-1]==')'
                {
                    if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(') //"()())" 最左不能判断，因为超出左边范围
                    {
                        if(i-dp[i-1]-2>=0) dp[i]=dp[i-dp[i-1]-2]+dp[i-1]+2;//"()-(-()())" -(-是最后)的配对左括号，但是-(-左边可能配对
                        else dp[i]=dp[i-1]+2;//-(-()()) -(-是最后)的配对左括号，但是再继续往左就超出边界了
                    }
                    else dp[i]=0;
                }
            }
        }
        int max_len=0;
        for(int i=0;i<n;i++)
        {
            max_len=max(max_len,dp[i]);
        }
        return max_len;
    }
};
```

栈方法思路：建立两个栈，这两个栈同步，一个用来装')',另一个用来装相应的index。注意第一个栈里面只有'(',不存在')',我们将符合有效括号的括号的index记录在一个int result[n]数组中，就是相当于将result[i]=1来代表该处的括号有效，当然，result[0]=0就是无效，最后我们就可以通过result[n]来判断有效括号的最大长度。

FROM XUEBI-IFCEN If this solution can help you, please click 'smile'

```
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n<=1) return 0;
        int result[n];
        memset(result,0,sizeof(result));
        stack<char> t;
        stack<int> num;//t和num栈同步，num用来记录num相对的char在原s中的index
        int i=0;
        while(i<n)//t栈里面都是'('哦
        {//必须要先考虑是否空栈，但是下面代码核心是考虑什么是有可能导致有效括号
            if(t.empty())//空栈
            {
                if(s[i]=='(')//这个'('在空栈的时候加入，可能导致有效
                {
                    t.push('('); num.push(i);
                } 
                //else 的情况：这个')'在空栈的时候加入，不可能导致有效，所以不加
            }
            else//非空栈
            {
                if(s[i]==')')//配对成功,其实相当于t.top()=='('&&s[i]==')'
                {
                    int tem=num.top();//去除t栈顶的'('的index
                    num.pop(); t.pop();
                    result[tem]=1; result[i]=1;
                }
                else if(s[i]=='(')//这个'('加入，可能导致有效
                {
                    t.push('('); num.push(i);               
                }
            } 
            i++;
        }
        int max_len=0;
        for(int i=1;i<n;i++)
        {
            if(result[i]!=0&&result[i-1]!=0)
            {
                result[i]+=result[i-1];
                max_len=max(result[i],max_len);
            }
        }
        return max_len;
    }
};
```


