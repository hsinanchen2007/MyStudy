### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    enum Result{
        True,False
    }
    // public boolean isMatch(String s, String p) {
    //     //1官方题解，回溯法，用递归实现回溯
    //     if(p.isEmpty()) return s.isEmpty();
    //     //如果不判断!s.isEmpty()，s.charAt(0)会出现下标越界异常
    //     boolean firstMatch=(!s.isEmpty()&&(s.charAt(0)==p.charAt(0)||p.charAt(0)=='.'));
    //     if(p.length()>=2&&p.charAt(1)=='*'){
    //         return (firstMatch&&isMatch(s.substring(1),p))||isMatch(s,p.substring(2));
    //     }
    //     else return firstMatch&&isMatch(s.substring(1),p.substring(1));
    // }

	//动态规划，自顶向下，根据回溯
	//dp[i][j]表示s[i:]是否和p[j:]匹配
	// public boolean isMatch(String s, String p) {
    //     //之所以是s.length()+1而不是s.length()，是为了最小单位的判断，null和null匹配为true
    //dp[i][j]表示s[i:]是否和p[j:]匹配，之所以要用Result来定义dp，是要防止boolean数组的默认值false会对推导产生误导
	// 	Result[][] dp=new Result[s.length()+1][p.length()+1];
	// 	return dpMatch(s,p,0,0,dp);
	// }
    // //判断s[i:]和p[j:]是否匹配
    // private boolean dpMatch(String s,String p,int i,int j,Result[][] dp){
    //     //重复子问题
    //     if(dp[i][j]!=null) return dp[i][j]==Result.True;
    //     boolean ans;
    //     if(j==p.length()) ans=i==s.length();
    //     else{
    //         boolean firstMatch=i<s.length()&&(s.charAt(i)==p.charAt(j)||p.charAt(j)=='.');
    //         if(j+1<p.length()&&p.charAt(j+1)=='*') ans=firstMatch&&dpMatch(s,p,i+1,j,dp)||dpMatch(s,p,i,j+2,dp);
    //         else ans=firstMatch&&dpMatch(s,p,i+1,j+1,dp);
    //     }
    //     dp[i][j]=ans?Result.True:Result.False;
    //     return ans;
    // }
    //动态规划，自底向上，就可以直接用boolean dp
    public boolean isMatch(String s, String p){
        boolean[][] dp=new boolean[s.length()+1][p.length()+1];
        dp[s.length()][p.length()]=true;
        //这里关于i j的初始值设定：一开始是想i=length-1,j=length-1，但是这样会出现推导用到了没有更改的错误的默认值false的情况
        //p=null,s要匹配必须为null;但是s=null，p可以为a*，一样匹配
        //所以，对于p=null,s!=null的情况必为false，也是默认值，不需要考虑，也就是二维数组的最右列，不需要考虑重新赋值
        //默认的false值就是正确的，所以j=length不用考虑
        for(int i=s.length();i>=0;i--){
            for(int j=p.length()-1;j>=0;j--){
                boolean firstMatch=i<s.length()&&(s.charAt(i)==p.charAt(j)||p.charAt(j)=='.');
                if(j+1<p.length()&&p.charAt(j+1)=='*') dp[i][j]=firstMatch&&dp[i+1][j]||dp[i][j+2];
                else dp[i][j]=firstMatch&&dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
    

}
```