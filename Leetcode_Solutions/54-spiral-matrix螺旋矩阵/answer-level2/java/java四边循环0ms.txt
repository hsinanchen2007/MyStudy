### 解题思路
此处撰写解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :37.5 MB, 在所有 Java 提交中击败了5.15%的用户
### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if(matrix.length==0) return result;
        int row1 = 0, row2 = matrix.length - 1;//定义上下行
        int column1 = 0, column2 = matrix[0].length - 1;//定义左右列
        while (row1 <= row2 && column1 <= column2) {
            for (int i = column1; i <= column2; i++) result.add(matrix[row1][i]);
            if (row1 == row2) break;//仅剩一行时退出
            for (int i = row1 + 1; i <= row2; i++) result.add(matrix[i][column2]);
            if (column1 == column2) break;//仅剩一列时退出
            for (int i = column2 - 1; i >= column1; i--) result.add(matrix[row2][i]);
            for (int i = row2 - 1; i >= row1 + 1; i--) result.add(matrix[i][column1]);
            row1++;
            column1++;
            row2--;
            column2--;
        }
        return result;

    }
}
```