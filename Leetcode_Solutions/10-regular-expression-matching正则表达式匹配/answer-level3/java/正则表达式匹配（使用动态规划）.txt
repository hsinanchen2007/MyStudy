
dp[i][j] ：s前i个字符是否能匹配p的前j个字符，从字符串末尾往前比较，因此要比较s[i-1]与p[i-1]。

确定状态方程之前先明确都会出现什么情况。首先就是s[i-1]与p[j-1]之间的关系，可能相等，可能不等。不等的情况下有三种情况：（1）p[j-1]为'*'，（2）p[j-1]为'.'（3）p[j-1]就是普通的一个字符。接下来对这些情况进行具体的解释。

一. s[i-1]==p[j-1]
那么dp[i][j]=dp[i-1][j-1]，也就是说只要判断s的前i-1个字符能否匹配p的前j-1个字符。

二. s[i-1]!=p[j-1]
1.p[j-1]=='.'
这种情况下dp[i][j]=dp[i-1][j-1]，也只要判断s的前i-1个字符能否匹配p的前j-1个字符。

2.p[j-1]=='*'
此时要分情况讨论，j-1位置的'*'号和它前面的字符组成星号组合，可以表示空字符串、一个j-2位置的字符、两个j-2位置的字符等等。

2.1 如果星号组合表示空格，又有两种可能情况
例如：s: abc  ; p: abcc*  ，此时s[i-1]==p[j-2]，此时dp[i,j]=dp[i][j-2]，还有一种情况：p[j-2]='.'

或是：s: abc  ; p: abcd*  ，此时s[i-1]!=p[j-2]，此时dp[i,j]=dp[i][j-2]

2.2 如果星号组合表示一个字符
 例如：s: abc  ; p: abc*   ，此时必然有s[i-1]==p[j-2]或者p[j-2]='.'，而dp[i,j]=dp[i][j-1]

2.3 如果星号组合表示多个字符
 例如：s: abcc  ; p: abc*   ，则dp[i,j]=dp[i-1][j]（因为有多个重复字符，所以可以删掉s串最末尾的继续进行匹配）
 这个时候必然有s[i-1]==p[j-2]或者p[j-2]='.'

归纳一下：
1.若s[i-1]==p[j-1]，则dp[i][j]=dp[i-1][j-1]
2.若p[j-1]=='.' ，则dp[i][j]=dp[i-1][j-1]  （1,2可以归纳到一起）
3.若p[j-1]=='*' ， （1）如果s[i-1]!=p[j-2] ，则dp[i,j]=dp[i][j-2]
                   （2）如果s[i-1]==p[j-2]或者p[j-2]='.'，
                    那么dp[i,j]=dp[i][j-2] 或者 dp[i,j]=dp[i][j-1] 或者 dp[i,j]=dp[i-1][j]

这里是比较细的拆分，其实星号组合表示一个字符的情况完全可以合并到星号组合表示多个字符中去


```
class Solution {
    public boolean isMatch(String s, String p) {
        if(s==null || p==null){
            return false;
        }
        int m=s.length();
        int n=p.length();
        boolean[][] dp=new boolean[m+1][n+1];//这里dp矩阵是要大一圈的，用来处理s或p为空串的情况
        dp[0][0]=true;//初始化dp[0][0]等于true，表示当两字符串长度都为0，也就是空字符串时，它们互相匹配
        //因为若是p串长度为0，不可能匹配，dp[i][0]均为false，没必要写，将初始化dp矩阵第一列省略了
        //下面初始化dp矩阵第一行，当s为空字符串时，要使p串匹配s串，p串最基本的表达形式是：a*a*a*a*a*
        //所以只看奇数位就可以，只要奇数位是*，就可以完全和空串匹配
        for(int j=2;j<=n;j++){
            if(p.charAt(j-1)=='*'){
                dp[0][j]=dp[0][j-2];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                char sc =s.charAt(i-1);
                char pc =p.charAt(j-1);
                if(sc==pc || pc=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }else if(pc=='*'){
                    if(sc!=p.charAt(j-2)&& p.charAt(j-2)!='.'){
                    //这里除了s[i-1]!=p[j-2]外，还有p[j-2]!='.'，在分析的时候没有写全面
                        dp[i][j]=dp[i][j-2];
                    }else {
                        dp[i][j]=dp[i][j-2] || dp[i][j-1] || dp[i-1][j];
                    }
                    
                }

            }

        }
        return dp[m][n];
        

    }


}
```

不难发现上面代码中`dp[i][j]=dp[i][j-2];`出现了两次，还可以再简化一下，在pc='*'的情况下，只要dp[i][j-2]匹配，那么dp[i][j]也匹配
```
class Solution {
    public boolean isMatch(String s, String p) {
        if(s==null || p==null){
            return false;
        }
        int m=s.length();
        int n=p.length();
        boolean[][] dp=new boolean[m+1][n+1];//这里dp矩阵是要大一圈的，用来处理s或p为空串的情况
        dp[0][0]=true;//初始化dp[0][0]等于true，表示当两字符串长度都为0，也就是空字符串时，它们互相匹配
        //因为若是p串长度为0，不可能匹配，dp[i][0]均为false，没必要写，将初始化dp矩阵第一列省略了
        //下面初始化dp矩阵第一行，当s为空字符串时，要使p串匹配s串，p串最基本的表达形式是：a*a*a*a*a*
        //所以只看奇数位就可以，只要奇数位是*，就可以完全和空串匹配
        for(int j=2;j<=n;j++){
            if(p.charAt(j-1)=='*'){
                dp[0][j]=dp[0][j-2];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                char sc =s.charAt(i-1);
                char pc =p.charAt(j-1);
                if(sc==pc || pc=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }else if(pc=='*'){
                    if(dp[i][j-2]){
                        dp[i][j]=true;
                    }else if(sc==p.charAt(j-2) || p.charAt(j-2)=='.') {
                        //dp[i][j]=dp[i][j-1] || dp[i-1][j];
                        //也可以将星号组合代表一个字符和多个字符的情况合并
                        dp[i][j]=dp[i-1][j];
                    }
                    
                }

            }

        }
        return dp[m][n];
        

    }


}
```

进一步优化
```
class Solution {
    public boolean isMatch(String s, String p) {
        if(s==null || p==null){
            return false;
        }
        int m=s.length();
        int n=p.length();
        boolean[][] dp=new boolean[m+1][n+1];//这里dp矩阵是要大一圈的，用来处理s或p为空串的情况
        dp[0][0]=true;//初始化dp[0][0]等于true，表示当两字符串长度都为0，也就是空字符串时，它们互相匹配
        //因为若是p串长度为0，不可能匹配，dp[i][0]均为false，没必要写，将初始化dp矩阵第一列省略了
        //下面初始化dp矩阵第一行，当s为空字符串时，要使p串匹配s串，p串最基本的表达形式是：a*a*a*a*a*
        //所以只看奇数位就可以，只要奇数位是*，就可以完全和空串匹配
        for(int j=2;j<=n;j++){
            if(p.charAt(j-1)=='*'){
                dp[0][j]=dp[0][j-2];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                char sc =s.charAt(i-1);
                char pc =p.charAt(j-1);
                if(pc !='*'){
                    dp[i][j]=dp[i-1][j-1] && match(sc,pc);
                }else {
                    dp[i][j]=dp[i][j-2] || (dp[i-1][j] && match(sc,p.charAt(j-2)));
                    
                }

            }

        }
        return dp[m][n];
        

    }
    public boolean match(char a,char b){
        return a==b || b=='.';
    }


}
```





