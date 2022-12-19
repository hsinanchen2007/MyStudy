## 解题思路

### 递归传递的参数： 
int[] matrix  矩阵
int i 行数   （当行数+1时，向下走格子；行数-1时，向上走格子）
int j 列数   （当列数+1时，向左走格子；列出+1时，向右走格子）
List<Integer> list  结果集

### 每一次递归要做的事情：
我们对走过的格子进行标记，将值设置成Integer.MAX_VALUE，并将其本来的值加入List中

1. 向右走到头，向下走到头，向左走到头，向上走到头
2. 判断当前格子的右一个格子是否被标记，如果没有，重复递归，如果有，退出。

### 递归终止的条件：
当前格子的右一个格子被标记过

## 代码

```java
class Solution {
    public  List<Integer> spiralOrder(int[][] matrix) {
    List<Integer> list = new ArrayList<>();
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return list;  // 防止[]坑
        }
        setWay(matrix, 0, -1, list); // 注意这里的 -1
        return list;
    }

    private  void setWay(int[][] matrix, int i, int j, List<Integer> list) {
        while (j + 1 < matrix[0].length && matrix[i][j + 1] != Integer.MAX_VALUE) {
            j++;  // 向右走
            list.add(matrix[i][j]);
            matrix[i][j] = Integer.MAX_VALUE;
        }
        while (i + 1 < matrix.length && matrix[i + 1][j] != Integer.MAX_VALUE) {
            i++;  // 向下走
            list.add(matrix[i][j]);
            matrix[i][j] = Integer.MAX_VALUE;
        }
        while (j - 1 >= 0 && matrix[i][j - 1] != Integer.MAX_VALUE) {
            j--;  // 向左走
            list.add(matrix[i][j]);
            matrix[i][j] = Integer.MAX_VALUE;
        }
        while (i - 1 >= 0 && matrix[i - 1][j] != Integer.MAX_VALUE) {
            i--; // 向上走
            list.add(matrix[i][j]);
            matrix[i][j] = Integer.MAX_VALUE;
        }
        if(j + 1 < matrix[0].length && matrix[i][j + 1] != Integer.MAX_VALUE){
            // 如果当前格子的右格子没走过，递归
            setWay(matrix,i,j,list);
        }
    }
}
```