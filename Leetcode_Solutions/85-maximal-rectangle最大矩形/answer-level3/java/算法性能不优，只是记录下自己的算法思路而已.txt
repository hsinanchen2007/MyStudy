### 解题思路
算法比较复杂，通过动态规划做。
新建一个和matrix相同大小的数组`result[n][m]`，而后对`i = 0 `和` j = 0`的边界点进行操作；
操作如下，以`i = 0, j = 0 ... m`为例
若`matrix[i][j] == '0'`，则`matrix[i][j] = matrix[i][j - 1]`;因为当前等于`'0'`表明无法组合成一个包含当前位置的矩形；
若`matrix[i][j] == '1'`，则从当前结点向前进行遍历，求出包含当前结点的最大矩阵，以`011101111`为例，当前结点最后一个1，此时进行向前遍历，碰到`matrix[i][k] == 0`结束j，此时`result[i][j] = Math.max(result[i][j - 1], area)`

对于其余结点，则进行如下操作：
1. 若`matrix[i][j] == '0'`时，则当前结点`result[i][j]`的值等于其上面结点`result[i - 1][j]`和其左边结点`result[i][j - 1]`的最大值；
2. 若`matrix[i - 1][j] == '0'`时，则当前结点`result[i][j]`只能是其左边结点`result[i][j - 1]`和当前结点往前找联系的'1'的个数的最大值；
3. 若`matrix[i - 1][j - 1] == '0'`时，则当前结点只能是上面结点`result[i - 1][j]`和当前结点往上推连续的'1'的个数，以及步骤2的情况四者的最大值
4. 余下，则是通过`h = j ... 0`，逐一进行遍历得到最大矩形面积：
- `h = j`时，得到连续的'1'的个数，并记录此时的连续的'1'个数`min`，并计算`area = min`；
- `h = j - 1`时，得到连续的matri[i][h]得到连续的'1'的个数并小于min的最小值，而后计算`area = Math.max(area, min * 2);`
- ...
- `h`时，`area = Math.max(area, min * (j - h + 1));`
- 最后比较`area，result[i - 1][j], result[i][j - 1]`三者的最大值，赋值给`result[i][j]`;
最后`return result[n - 1][m - 1];`

### 代码

```java
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if(matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) return 0;
        int n = matrix.length, m = matrix[0].length;
        int[][] result = new int[n][m];
        result[0][0] = matrix[0][0] == '0' ? 0 : 1;

        calculatingColumn(result, matrix, 1, 0);
        calculatingRow(result, matrix, 0 ,1);

        for(int i = 1; i < n; i ++){
            for(int j = 1; j < m; j ++){
                if(matrix[i][j] == '0'){
                    result[i][j] = Math.max(result[i][j - 1], result[i - 1][j]);
                }else {
                	int area = 0;
                    if(matrix[i - 1][j] == '0'){
                        int k = j - 1;
                        while(k >= 0 && matrix[i][k] == '1') k --;
                        area = j - k;
                    }else if(matrix[i - 1][j - 1] == '0'){
                        int k = i - 1;
                        while(k >= 0 && matrix[k][j] == '1') k --;
                        area = i - k;
                        k = j - 1;
                        while(k >= 0 && matrix[i][k] == '1') k --;
                        area = Math.max(area, j - k);
                    }else {
                        int h = j;
                        int min = i + 1;
                        while(h >= 0){
                            int k = i;
                            while(k >= 0 && matrix[k][h] == '1' && i - k < min) k --;
                            if(i - k <= min){
                                min = i - k;
                                area = Math.max(area, (j - h + 1) * min);
                            }
                            h --;
                        }
                    }
                    result[i][j] = Math.max(area, Math.max(result[i][j - 1], result[i - 1][j]));
                }
            }
        }
        return result[n - 1][m - 1];
    }
    public void calculatingColumn(int[][] result, char[][] matrix, int i, int j){
        for(i = 1; i < matrix.length; i ++){
            if(matrix[i][j] == '0') result[i][j] = result[i - 1][j];
            else {
                int k = i - 1;
                while(k >= 0 && matrix[k][j] == '1'){
                    k --;
                }
                result[i][j] = Math.max(result[i - 1][j], i - k);
            }
        }
    }

    public void calculatingRow(int[][] result, char[][] matrix, int i, int j){
        for(j = 1; j < matrix[0].length; j ++){
            if(matrix[i][j] == '0') result[i][j] = result[i][j - 1];
            else {
                int k = j - 1;
                while(k >= 0 && matrix[i][k] == '1'){
                    k --;
                }
                result[i][j] = Math.max(result[i][j - 1], j - k);
            }
        }
    }
}
```