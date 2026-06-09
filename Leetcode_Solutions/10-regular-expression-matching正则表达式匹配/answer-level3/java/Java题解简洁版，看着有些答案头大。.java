### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isMatch(String ss, String pp) {
        char[] s = ss.toCharArray();
        char[] p = pp.toCharArray();
        int m = s.length;
        int n = p.length;
        //f[i][j]表示s的前i个字符能否与p的前j个字符匹配
        boolean[][] f = new boolean[m+1][n+1];
        f[0][0] = true;
        for(int i = 1; i <= m; i++){
            f[i][0] = false;
        }
        for(int j = 1; j <= n; j++){
            if(j > 1 && p[j-1] == '*'){
                f[0][j] = f[0][j-2];
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[j-1] != '*'){
                    f[i][j] = match(s[i-1],p[j-1]) && f[i-1][j-1];
                }else{
                    f[i][j] = f[i][j-2] || match(s[i-1],p[j-2]) && f[i-1][j];
                }
            }
        }
        return f[m][n];
    }
    private boolean match(char c1, char c2){
        return c1 == c2 || c2 == '.';
    }
}
```