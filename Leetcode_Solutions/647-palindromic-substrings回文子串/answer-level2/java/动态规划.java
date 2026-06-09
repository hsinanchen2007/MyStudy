时间复杂度: O(n^2) 
空间复杂度: O(n)
```java
class Solution {
    public int countSubstrings(String s) {
        if(s.equals("")) return 0;
        int res=s.length();
        boolean[][] dp=new boolean[2][s.length()];
        for(int i=0;i<s.length();i++){ //初始化长度为1,2的情况
            dp[0][i]=true;
            if(i+1<s.length()&&s.charAt(i)==s.charAt(i+1)){
                dp[1][i]=true;
                res+=1;
            }
        }
        for(int L=2;L<s.length();L++){
            for(int i=0;i+L<s.length();i++){
                dp[L%2][i]=false;
                if(s.charAt(i)==s.charAt(i+L)&&dp[L%2][i+1]){
                    dp[L%2][i]=true;
                    res+=1;
                }
            }
        }
        return res;
    }
}

```
