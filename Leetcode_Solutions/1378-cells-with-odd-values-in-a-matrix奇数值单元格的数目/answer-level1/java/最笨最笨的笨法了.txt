### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        //根据n和m构建这个矩阵
        int res = 0;
        int[][] initM = new int[n][m];
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                initM[i][j] = 0;
            }
        }

         //遍历indices，对矩阵的值进行变换
        for(int i = 0;i < indices.length;i++){
            //这个是要加的行数indices[i][0]
            //这个是要加的列数indices[i][1]
            for(int j = 0; j < m; j++){
                initM[indices[i][0]][j] += 1;
            }
            for(int k = 0; k < n;k++){
                initM[k][indices[i][1]] += 1;
            }
        }

        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                if(initM[i][j] % 2 != 0){
                    res++;
                }
            }
        }

        return res;
        
    }
}
```