### 解题思路
对于这种题，首先我们要思考的就是，我们要考虑到那些情况，只有把这些会错出的情况考虑完全才能做的出来，不然是很难写出来了，同样我们可以定义一个一维数组dp[]来记录每一步的方法数，但是也是可以不定义的，下面的代码中会体现出来。
对于本题有以下几种情况：
1.当s[i]=0时，我们应该考虑s[i-1]的值，只有s[i-1]='1'或s[i-1]='2'时才符合情况 此时dp[i]=dp[i-2]
2.当s[i]!=0时，s[i-1] 的值应该为 0,1或2 
  当s[i-1]='2' 时 s[i]<=6 这一点大家应该可以想的清楚 此时dp[i]=dp[i-1]+dp[i-2]
  当s[i-1]='0'时 s[i-1]只能和s[i-2]组合符合所以此时dp[i]=dp[i-2]
因为在求dp[i]时只用到了它的前两个dp[i-1],dp[i-2]所以可以用两个变量pre,current来代表dp[i-1],dp[i-2]
下面给出一个示例图：

![image.png](https://pic.leetcode-cn.com/a6df3804509089a4923b86b32a9f57e3c5aaa2e438dde1b31bf379d0acdb4f2a-image.png)

对照代码应该很容易看懂
### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
        {return 0;}
        int pre=1;
        int current=1;
        for(int i=1;i<s.length();i++)
        {
            int temp=current;
            if(s[i]=='0')
            {
                if(s[i-1]!='1'&&s[i-1]!='2')
                {
                  return 0;
                }
                current=pre;
            }
            else
            {
                if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6'))
                {
                    current+=pre;
                }
            }
            pre=temp;
        }
        return current;
    }
};
```