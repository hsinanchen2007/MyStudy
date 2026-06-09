### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
        if(m == 0 || n == 0){
            return 0;
        }
        // 该数组用来存储到每个点的路径总数
        int[][] pathNum = new int[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    pathNum[0][0] = 1;
                    continue;
                }
                // 第一行只能从左边过来
                if(i == 0){
                    pathNum[i][j] = pathNum[i][j-1];
                    continue;
                }
                // 第一列只能从上边过来
                if(j == 0){
                    pathNum[i][j] = pathNum[i-1][j];
                    continue;
                }
                else{
                    pathNum[i][j] = pathNum[i][j-1] + pathNum[i-1][j];
                }
            }
        }
        return pathNum[m-1][n-1];

    }
}
```