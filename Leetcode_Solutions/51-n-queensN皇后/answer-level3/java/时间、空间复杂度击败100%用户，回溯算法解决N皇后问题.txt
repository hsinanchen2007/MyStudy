在 n*n 的矩阵中摆放 n 个皇后，并且每个皇后不能在同一行，同一列，同一对角线上，求所有的 n 皇后的解。

一行一行地摆放，在确定一行中的那个皇后应该摆在哪一列时，需要用三个标记数组来确定某一列是否合法，这三个标记数组分别为：列标记数组、45 度对角线标记数组和 135 度对角线标记数组。

45 度对角线标记数组的长度为 2 * n - 1，通过下图可以明确 (r, c) 的位置所在的数组下标为 **r + c**。
![9c422923-1447-4a3b-a4e1-97e663738187.jpg](https://pic.leetcode-cn.com/84d9254d43b245a8059c45a0346b41058d9c28e213bd9cb2e6a45a0ffd89b26e-9c422923-1447-4a3b-a4e1-97e663738187.jpg)

135 度对角线标记数组的长度也是 2 * n - 1，(r, c) 的位置所在的数组下标为 **n - 1 - (r - c)**。
![7a85e285-e152-4116-b6dc-3fab27ba9437.jpg](https://pic.leetcode-cn.com/7569d93244f55f139f7ed4a888ba94180519f72a873fd0e469d4f20172e0f15d-7a85e285-e152-4116-b6dc-3fab27ba9437.jpg)

```java []
class Solution {
    private List<List<String>> result;
    private char[][] nQueens;
    private boolean[] colUsed;
    private boolean[] diagonal1; //45度对角线
    private boolean[] diagonal2; //135度对角线
    private int n;
    private void backtrack(int row) {
        if (row == n) {
            List<String> temp = new ArrayList<>();
            for (char[] chars : nQueens) {
                temp.add(new String(chars));
            }
            result.add(temp);
            return;
        }
        for (int col = 0; col < n; col++) {
            int index1 = col + row; //45度对角线索引
            int index2 = n - 1 - (row - col); //135度对角线索引
            if (colUsed[col] || diagonal1[index1] || diagonal2[index2]) {
                continue;
            }
            nQueens[row][col] = 'Q';
            colUsed[col] = diagonal1[index1] = diagonal2[index2] = true;
            backtrack(row + 1);
            colUsed[col] = diagonal1[index1] = diagonal2[index2] = false;
            nQueens[row][col] = '.';
        }
    }
    public List<List<String>> solveNQueens(int n) {
        result = new ArrayList<>();
        nQueens = new char[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(nQueens[i], '.');
        }
        colUsed = new boolean[n];
        diagonal1 = new boolean[2 * n - 1];
        diagonal2 = new boolean[2 * n - 1];
        this.n = n;
        backtrack(0);
        return result;
    }
}
```
![Screen Shot 2019-12-17 at 14.50.12.png](https://pic.leetcode-cn.com/cca38f1619f8261eb9df44e3b5e25047f7b6153fa6f3cbd0a14b435560a8e690-Screen%20Shot%202019-12-17%20at%2014.50.12.png)





