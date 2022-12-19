
### 思路：
分别将当前矩阵最外圈的上、右、下、左边遍历输出并逐步缩减行列范围（注意检测是否越界），也算是一种动态规划吧。

### 时间复杂度：
### O(n)
### 空间复杂度：
### O(n)

### 代码
```java
/**java实现：
 *执行用时 : 1 ms, 在所有 Java 提交中击败了 97.22%的用户
 *内存消耗 :41 MB, 在所有 Java 提交中击败了100.00%的用户
 */
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        //空矩阵
        if(matrix.length == 0) return new int[0];

        int rows = matrix.length;
        int lines = matrix[0].length;
        //左、右
        int l = 0;
        int r = lines - 1;
        //上、下
        int u = 0;
        int d = rows - 1;
        //当矩阵仍未输出完时 i、j分别控制行、列
        int i = 0;
        int j = 0;
        //存储矩阵元素的数组
        int[] res = new int[rows * lines];
        int ri = 0;
        while(l <= r && u <= d){
            //遍历上、右、下、左，并逐步缩小
            for(j = l; j <= r; j++){
                if(ri == res.length) break;
                res[ri++] = matrix[u][j];
            }
            u++;    
            for(i = u; i <= d; i++){
                if(ri == res.length) break;
                res[ri++] = matrix[i][r];
            }
            r--;
            for(j = r; j >= l; j--){
                if(ri == res.length) break;
                res[ri++] = matrix[d][j];
            }
            d--;
            for(i = d; i >= u; i--){
                if(ri == res.length) break;
                res[ri++] = matrix[i][l];
            }
            l++;    
        }
        return res;
    }
}
```
