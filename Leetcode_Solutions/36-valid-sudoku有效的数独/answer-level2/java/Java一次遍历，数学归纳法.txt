这道题并不难。只要我们找到数组下标跟行、列、块元素的对应关系，就能用简洁的一次遍历写出解答。
首先，我们需要像这样遍历所有元素，在内层循环中判断元素的重复情况：
```
for(int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        //do something
    }
}
```
其次，对于重复元素的检查，我选择使用三个set，每次遍历行/列/块时使用`add(element)`的返回值来判断元素是否重复，内层循环执行完成后清空三个set。

对于行和列，关系比较简单：
```
board[i][j]表示第i行的元素 j从0迭代到8
board[j][i]表示第i列的元素 j从0迭代到8
```
因此在内层循环中，我们可以很轻松写出这样的代码：
```
if (board[i][j] != '.' && !rowSet.add(board[i][j]))
    return false;
if (board[j][i] != '.' && !columnSet.add(board[j][i]))
    return false;
```
但是对于块，关系不是一眼就能看出来。首先，我们如何找到每个块有哪些元素呢？换句话说，我们如何定位到某个块的位置呢？只要我们定位到每个块的第一个元素`board[m][n]`，那我们就能写出块中所有元素和`j`的值的关系：
```
j = 0   board[m][n]
j = 1   board[m][n + 1]
j = 2   board[m][n + 2]
j = 3   board[m + 1][n]
j = 4   board[m + 1][n + 1]
j = 5   board[m + 1][n + 2]
j = 6   board[m + 2][n]
j = 7   board[m + 2][n + 1]
j = 8   board[m + 2][n + 2]
```
即关系为`board[m + j / 3][n + j % 3]`。这样，我们可以写出下面的代码：
```
if (board[m + j / 3][n + j % 3] != '.' && !blockSet.add(board[m + j / 3][n + j % 3]))
    return false;
```
思考一下，九宫格中一共有9个3x3的块，刚好和外部循环的`i`值对应，就是说，`i`每增加`1`，都表示我们进入了下一个块中。所以我们猜想每个块的第一个元素`board[m][n]`肯定和`i`有关。于是我们写出：
```
i = 0   board[0][0]
i = 1   board[0][3]
i = 2   board[0][6]
i = 3   board[3][0]
i = 4   board[3][3]
i = 5   board[3][6]
i = 6   board[6][0]
i = 7   board[6][3]
i = 8   board[6][6]
```
因此关系为：
```
m = i / 3 * 3;
n = i % 3 * 3;
```
最终代码：

```java []
public boolean isValidSudoku(char[][] board) {
    HashSet<Character> rowSet = new HashSet<>();
    HashSet<Character> columnSet = new HashSet<>();
    HashSet<Character> blockSet = new HashSet<>();
    for(int i = 0; i < 9; i++) {
        int m = i / 3 * 3;
        int n = i % 3 * 3;
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.' && !rowSet.add(board[i][j]))
                return false;
            if (board[j][i] != '.' && !columnSet.add(board[j][i]))
                return false;
            if (board[m + j / 3][n + j % 3] != '.' && !blockSet.add(board[m + j / 3][n + j % 3]))
                return false;
        }
        rowSet.clear();
        columnSet.clear();
        blockSet.clear();
    }
    return true;
}
```