
```java
class Solution {
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        
        int[][] f = new int[n+1][m+1];
        // 第1个字符串为空, 第二个字符串为i个字符时, 需要i次插入操作
        for(int i = 0; i <= m; i++) f[0][i] = i; 
        // 第1个字符串为i个字符, 第二个字符串为空时, 需要i次删除操作
        for(int i = 0; i <= n; i++) f[i][0] = i; 
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // 最后一步w1删除一个w1[i]->w2
                // 意味着w1前i-1个字符与w2的前j个字符相同
                f[i][j] = Math.min(f[i-1][j], f[i][j-1]) + 1;
                if(word1.charAt(i-1) != word2.charAt(j-1)){
                    f[i][j] = Math.min(f[i-1][j-1] + 1, f[i][j]);
                }else{
                    f[i][j] = Math.min(f[i-1][j-1], f[i][j]);
                }
            }
        }
                                         
        return f[n][m];        
    }
}
```