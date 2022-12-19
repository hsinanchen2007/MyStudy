### 解题思路
此处撰写解题思路
先从1开始遍历字符串，因为是括号，所以从0判断没有意义，
如果是（，就直接设为0，dp[i]记录以i为重点的子串其最长的合法括号长度
如果碰到），
那么要看前一位是不是（，
如果是，
    则必定要+2了，那么就是dp[i-2]+2，这里要判断i-2的index检索合法性是否大于等于0，
    如果i>=2，即合法，那么就是dp[i]=dp[i-2]+2
    如果i<2,  即不合法，那么就是dp[i]=2;
    即dp[i]= (i>=2?dp[i-2]:0) + 2;
如果不是
    那么前面就是)，那么有两种情况，
    一种是xxx（（））
        此处dp[i]=dp[i-1]+2+len(xxx)
    另一种是))))))
        此处dp[i]=0
第一种情况需要判定（（））1234，当前是4，判定1是否为(,
为什么是1，因为这是s[i-dp[i-1]-1]的位置，可以得到是否存在相对匹配的(
那么结论就是
如果i-dp【i-1】-1>=0 即 i-dp[i-1]>0 && s[i-dp[i-1]-1]=='(' 的情况下：
    dp【i】=dp[i-1]+(i-dp[i-1]-2>=1 ? dp[i-dp[i-1]-2]:0 )+2
                    大于等于1的要求与上述第一情况一样，即上一个XXX的要求，因为括号的双数性，在0123里面，如果他<1，就意味着他只是一个单括号，不管是左括号还是有括号，都没有意义，都为0长度的有效子串。

否则，dp[i]=0;



### 代码

```java
class Solution {
    public int longestValidParentheses(String s) {
        int len=s.length();
        int[] dp=new int[len];
        int max_len=0;
        for(int i=1;i<len;i++)
        {
           if(s.charAt(i)==')')
           {
               if(s.charAt(i-1)=='(')
               {
                   dp[i]= 2+(i>=2? dp[i-2]:0);
               }
               else if((i-dp[i-1])>0 && s.charAt(i-dp[i-1]-1)=='(')
               {
                   dp[i]=dp[i-1]+(i-dp[i-1]>2? dp[i-dp[i-1]-2]:0)+2;
               }
           }
           max_len=Math.max(max_len,dp[i]);
        }
        return max_len;

    }
}

```