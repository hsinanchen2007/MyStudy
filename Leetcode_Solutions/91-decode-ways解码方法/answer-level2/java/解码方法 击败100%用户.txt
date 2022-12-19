### 解题思路
1.分析不同字符串长度下的解码个数，并找出依赖关系。
2.分两种情况：
        1.当前数字是0：
            不好意思，这阶楼梯不能单独走，
            dp[i] = dp[i-2]
        2.当前数字不是0
            不好意思，这阶楼梯太宽，走两步容易扯着步子，只能一个一个走
            dp[i] = dp[i-1];
3.最终结束条件：只要遇到解码方法数为0的情况，直接break;

### 代码

```java
class Solution {
    public int numDecodings(String s) {
        if(s==null||s.charAt(0)=='0'||s.length()==0) return 0;
        int n=s.length();
        int[] dp=new int[n+1];//
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            if(s.charAt(i-1)=='0'){
               if(s.charAt(i-2)>'0'&&s.charAt(i-2)<'3'){
                   dp[i]+=dp[i-2];
                }else{
                   break;
                }
            }else{
                dp[i]+=dp[i-1];
                if(s.charAt(i-2)=='1'||s.charAt(i-2)=='2'&&s.charAt(i-1)<='6'){
                    dp[i]+=dp[i-2];
                }
            }
            
        }
        return dp[n]; 
    }
}
```