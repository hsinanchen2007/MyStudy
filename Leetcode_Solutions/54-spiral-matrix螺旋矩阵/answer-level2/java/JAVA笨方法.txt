### 解题思路
用递归思路，从外向内旋转读取。
![QQ图片20200315222513.png](https://pic.leetcode-cn.com/d4768d6b191e7506408c56c25240555ce919dc3788272b1c53909b9200ef6142-QQ%E5%9B%BE%E7%89%8720200315222513.png)

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<Integer>();
        if (matrix.length == 0 || matrix[0].length == 0) return result;
        if (matrix.length == 1){
            for (int i = 0;i <= matrix[0].length-1;i++){
                result.add(matrix[0][i]);
            }
            return result;
        }
        if (matrix[0].length == 1){
            for (int i = 0;i <= matrix.length-1;i++){
                result.add(matrix[i][0]);
            }
            return result;
        }

        dfs(result,0,0,matrix,matrix.length,matrix[0].length);

        return result;
    }

    public void dfs(List<Integer> result, int row, int col, int[][] matrix, int surplusRows, int surplusCols){
        if (surplusRows == 0 || surplusCols == 0) return;
        if (surplusRows == 1) {
            for (int i = col;i <= col + surplusCols - 1;i++){
                result.add(matrix[row][i]);
            }
            return;
        }
        if (surplusCols == 1){
            for (int i = row;i <= row + surplusRows - 1;i++){
                result.add(matrix[i][col]);
            }
            return;
        }

        for (int i = col;i <= col + surplusCols - 1;i++){
            result.add(matrix[row][i]);
        }

        for (int i = row+1;i <= row + surplusRows - 1;i++){
            result.add(matrix[i][col + surplusCols - 1]);
        }

        for (int i = col + surplusCols - 2;i >= col;i--){
            result.add(matrix[row + surplusRows - 1][i]);
        }

        for (int i = row + surplusRows - 2;i >= row+1;i--){
            result.add(matrix[i][col]);
        }

        dfs(result,row+1,col+1,matrix,surplusRows-2,surplusCols-2);
    }
}
```