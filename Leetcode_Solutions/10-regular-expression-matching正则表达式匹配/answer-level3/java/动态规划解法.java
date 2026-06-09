解析：这道题用动态规划进行求解的时候，定义dp[i][j]为s从0到i的子串和模式串p从0到j的子串是否能够匹配。
 1、当模式串扫描到' . '的时候,那么当dp[i-1][j-1]匹配的时候，dp[i][j]就匹配
 2、当模式串扫描到' * '的时候，那么当模式串的前一个字符和配匹配的子串的最后一个字符相等的时候（这个相等可能是真正的相等，也
 可能是模式串是'.'的相等），就能根据dp[i-1][j]进行判断。
 3、当模式串扫描的非'.'并且非' * '的时候，那么就只能根据dp[i-1][j-1]进行判断。
这一题的关键还有扫描开始的位置，对于被匹配的字符串来说，扫描必须是从空字符串开始，因为需要考虑这种情况：
 s:"a"
 p:"c * a"
当扫描到dp[1][3]的时候，不能直接根据，dp[0][2]得到不相符，因为，" c* " 完全可以不使用，所以需要提前将这种空字符串的判断考虑进去。


```
public boolean isMatch(String s, String p) {
        int lenS = s.length();
        int lenP = p.length();
        boolean[][] dp = new boolean[lenS+1][lenP+1];
        dp[0][0] = true;
        for(int i=0;i<=lenS;i++){
            for(int j=1;j<=lenP;j++){
                if(p.charAt(j-1) == '.'){
                    if(i>0){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = false;
                    }
                }else if(p.charAt(j-1) == '*'){
                    if(i>0 && (((j>=2) &&dp[i][j-2]) || (((s.charAt(i-1) == p.charAt(j-2) || p.charAt(j-2) == '.'))&&dp[i-1][j]))){
                        dp[i][j] = true;
                    }else{
                        if(i == 0 && j>=2){
                            dp[i][j] = dp[0][j-2];
                        }
                    }
                }else{
                    if(i>0 && s.charAt(i-1) == p.charAt(j-1) && dp[i-1][j-1]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[lenS][lenP];
    }
```
