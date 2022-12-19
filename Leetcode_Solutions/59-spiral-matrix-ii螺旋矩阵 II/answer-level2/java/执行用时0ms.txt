### 解题思路

跟螺旋矩阵的上一题相同，用厚度来来遍历矩阵，这道题要求的是方阵，所以只需要在n是奇数时在矩阵正中心填一个数字即可。

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int idx = 1;
        for(int i =0;i<n/2;i++){
            for(int j = i;j<n-i-1;j++){
                res[i][j] = idx++;
            }
            for(int j = i;j<n-i-1;j++){
                res[j][n-i-1] = idx++;
            }
            for(int j =n-i-1;j>i;j--){
                res[n-i-1][j] = idx++;
            }
            for(int j = n-i-1;j>i;j--){
                res[j][i] = idx++;
            }
        }
        if(n>1 && n%2==1){
            res[n/2][n/2] = idx;
        }
        if(n==1){
            res[0][0] = 1;
        }
        return res;
    }
}
```