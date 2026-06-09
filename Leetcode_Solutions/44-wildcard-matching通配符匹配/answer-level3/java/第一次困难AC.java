### 解题思路

解法不好，只是纪念一下自己第一次解决了困难题，相信之后会更多的，嗯，加油！

### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {
        if(s==null) return p==null;
        if(p==null) return s==null;
        int m = s.length();
        int n = p.length();
        boolean[][] f = new boolean[m+1][n+1];
        f[0][0] = true;

        for(int i=0; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(p.charAt(j-1) == '*'){
                    for(int k=i; k>=0; k--){
                        if(f[k][j-1]){
                            f[i][j] = true;
                            break;
                        }
                    }
                }else{
                    f[i][j] = (i>0) && (p.charAt(j-1)=='?'||s.charAt(i-1)==p.charAt(j-1)) 
                                && f[i-1][j-1];
                }
            }
        }

        return f[m][n];
    }
}
```