### 解题思路
1.遇到s和p都是""则直接返回true
2.判断边界条件如果s串已经遍历完毕，则判断p串是否便利完毕，如果p串长度大于s串，则判断大于部分是否都是*，如果是则返回true，否则返回false
3.判断边界条件如果p串已经便利完毕，则判断s串是否便利完毕，是则返回true，否则返回false 
4.判断字符是否相等
5.如果p串当前字符是*则有两种可能，第一种是忽略*继续匹配，第二种是，继续匹配s剩余字符

### 代码

```java
enum Result {
    TRUE, FALSE
}
class Solution {
    Result[][] dp;

    public boolean isMatch(String s, String p) {
        //s和p为空时直接返回true
        if(s.isEmpty()&&p.isEmpty()){
           return true;
        }else{
            dp = new Result[s.length()+1][p.length()+1];
            return compute(s,p,0,0);
        }
    }

    public boolean compute(String s, String p,int i,int j){
        if (dp[i][j] != null) {
            return dp[i][j] == Result.TRUE;
        }
        boolean ans;
        if(j==p.length()){
            ans=i==s.length();
        }else if(i==s.length()){
            ans=j==p.length();
            //需要额外判断剩下的Pattern是否都为*
            int count =p.length()-j;
            if(count>0){
                ans=true;
                for(int t=0;t<count;t++){if(p.charAt(j+t)!='*'){ans=false;break;}}
            }
        }else{
            boolean firstMatch = ((s.charAt(i)==p.charAt(j))||(p.charAt(j)=='?')||(p.charAt(j)=='*'));
            if(p.charAt(j)=='*'){
                ans=firstMatch&&((compute(s,p,i+1,j))||(compute(s,p,i,j+1)));
            }else{
                ans=firstMatch&&compute(s,p,i+1,j+1);
            }
        }
        dp[i][j] = ans ? Result.TRUE : Result.FALSE;
        return ans;
    }
}
```