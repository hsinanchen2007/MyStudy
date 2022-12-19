## 思路:

首先还是理清题意，就是每一行、每一列、每一个小正方形都不能重复出现相同数字,如下图所示：


![Snipaste_2019-05-08_15-33-58.png](https://pic.leetcode-cn.com/48973835efb916f1d216c2b1dbf460fb19f9757825573962b7eba8a967d11a99-Snipaste_2019-05-08_15-33-58.png){:width=200}
{:align=center}

所以我们最直接想到就是，就是记录它的行，列和小正方形的值，有重复就`false`。

**思路一：**

我们用一个字典，分别记录行，列，和小正方形！

行,列我们直接可以用数字表示，小正方形如何表示呢？

这里,我们发现一个规律,我们可以把小正方形变成用二维唯一标识,比如`(0,0)`表示左上角那个,`(1,1)`表示中间那个,他们和行列的关系就是`(i//3,j//3)`，

所以任何位置我们都能找出它在哪个行，哪个列，哪个小正方形里！

时间复杂度都是常数级的。

**思路二：**


我们有个小技巧,我们只需要用一个集合就可以搞定!

比如我们把`board[i][j]`

用字符串：

表示行：`(i)` + `board[i][j]`

表示列：`board[i][j]`  + `(j)`

表示小正方形：`(i)` + `board[i][j]` +  `(j)`

就直接可以用一个集合搞定！

## 代码：

思路一

```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        from collections import defaultdict
        row = defaultdict(set)
        col = defaultdict(set)
        small_square = defaultdict(set)
        
        for i in range(9):
            for j in range(9):
                if board[i][j].isdigit():
                    if board[i][j] not in row[i] \
                    and board[i][j] not in col[j] \
                    and board[i][j] not in small_square[(i // 3,j // 3)]:
                        row[i].add(board[i][j]) 
                        col[j].add(board[i][j])
                        small_square[(i // 3, j // 3)].add(board[i][j])
                    else:
                        return False
        return True
```



思路二


```python [1]
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        one_set = set()
        
        for i in range(9):
            for j in range(9):
                if board[i][j].isdigit():
                    row = "(" + str(i) + ")" + board[i][j]
                    col = board[i][j] + "(" + str(j) + ")"
                    small_square = "(" + str(i//3)+ ")" + board[i][j] +  "(" + str(j//3) + ")"
                    if row in one_set or col in one_set or small_square in one_set:
                        return False
                    one_set.update([row,col,small_square])
        return True
```


```java [1]
class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<String> one_set = new HashSet<>();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    String row = "(" + i + ")" + board[i][j];
                    String col = board[i][j] + "(" + j + ")";
                    String small_square = "(" + i / 3 + ")" + board[i][j] + "(" + j / 3 + ")";
                    if (!one_set.add(row) || !one_set.add(col) || !one_set.add(small_square)) return false;
                }
            }
        }
        return true;
        
    }
}
```

