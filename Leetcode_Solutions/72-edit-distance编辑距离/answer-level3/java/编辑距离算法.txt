### 解题思路
此处撰写解题思路，官方解题思路，dij的最短距离，等于di-1,j/di,j-1/di-1,j-1距离的最小值，其中di-1,j-1的值当i-1,j-1值相等时为di-1,j-1否则需要加1.

### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int n=word1.length();
        int m=word2.length();
        if(n*m==0){
            return m+n;
        }
        int [][]d=new int[n+1][m+1];
        for(int i=0;i<n+1;i++){
            d[i][0]=i;
        }
         for(int j=0;j<m+1;j++){
            d[0][j]=j;
        }
        for (int i = 1; i < n + 1; i++) {
           for (int j = 1; j < m + 1; j++) {
            int left = d[i - 1][j] + 1;
            int down = d[i][j - 1] + 1;
            int left_down = d[i - 1][j - 1];
            if (word1.charAt(i - 1) != word2.charAt(j - 1))
                 left_down += 1;
            d[i][j] = Math.min(left, Math.min(down, left_down));

           }
        }
     return d[n][m];

    }
   
   
}
```