## 想法

我们从第一个网格开始依次遍历整个board。对于每一个网格我们都执行dfs，如果不满足word的要求，我们回溯尝试其他可能。 为了防止无限循环，我们需要记录当前DFS链路中已经访问的元素，我们不妨使用一个visited的集合。

## 关键点

- 回溯的时候要清除visited

## 代码

Python Code:

```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        if m == 0:
            return False
        n = len(board[0])
        visted = set()

        def dfs(i, j, cur):
            if (i, j) in visted:
                return False
            if i < 0 or i >= m or j < 0 or j >= n:
                return False
            if board[i][j] != word[cur]:
                return False
            if cur == len(word) - 1:
                return True
            visted.add((i, j))
            res = dfs(i + 1, j, cur + 1) \
                or dfs(i - 1, j, cur + 1) \
                or dfs(i, j + 1, cur + 1) \
                or dfs(i, j - 1, cur + 1)
            visted.remove((i, j))
            return res

        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False

# @lc code=end
```


Java Code:


```java
public class LC79WordSearch {
  public boolean exist(char[][] board, String word) {
    if (board == null || board.length == 0 || board[0].length == 0
        || word == null || word.length() == 0) return true;
    int rows = board.length;
    int cols = board[0].length;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        // scan board, start with word first character 
        if (board[r][c] == word.charAt(0)) {
          if (helper(board, word, r, c, 0)) {
            return true;
          }
        }
      }
    }
    return false;
  }
  
  private boolean helper(char[][] board, String word, int r, int c, int start) {
    // already match word all characters, return true
    if (start == word.length()) return true;
    if (!isValid(board, r, c) ||
        board[r][c] != word.charAt(start)) return false;
    // mark visited
    board[r][c] = '*';
    boolean res = helper(board, word, r + 1, c, start + 1)
        ||  helper(board, word, r, c + 1, start + 1)
        ||  helper(board, word, r - 1, c, start + 1)
        ||  helper(board, word, r, c - 1, start + 1);
    // backtracking to start position
    board[r][c] = word.charAt(start);
    return res;
  }
  
  private boolean isValid(char[][] board, int r, int c) {
    return r >= 0 && r < board.length && c >= 0 && c < board[0].length;
  }
}
```
JavaScript Code:

```javascript
/*
 * @lc app=leetcode id=79 lang=javascript
 *
 * [79] Word Search
 */
function DFS(board, row, col, rows, cols, word, cur) {
  // 边界检查
  if (row >= rows || row < 0) return false;
  if (col >= cols || col < 0) return false;

  const item = board[row][col];

  if (item !== word[cur]) return false;

  if (cur + 1 === word.length) return true;

  // If use HashMap keep track visited letters, then need manual clear HashMap for each backtrack which needs extra space.
  // here we use a little trick
  board[row][col] = null;

  // UP, DOWN, LEFT, RIGHT
  const res =
    DFS(board, row + 1, col, rows, cols, word, cur + 1) ||
    DFS(board, row - 1, col, rows, cols, word, cur + 1) ||
    DFS(board, row, col - 1, rows, cols, word, cur + 1) ||
    DFS(board, row, col + 1, rows, cols, word, cur + 1);

  board[row][col] = item;

  return res;
}
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
  if (word.length === 0) return true;
  if (board.length === 0) return false;

  const rows = board.length;
  const cols = board[0].length;

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      const hit = DFS(board, i, j, rows, cols, word, 0);
      if (hit) return true;
    }
  }
  return false;
};
```

**复杂度分析**
- 时间复杂度：每一个格子，都可能回溯整个board。 因此时间复杂度为  $O((M * N) ^ 2)$
- 空间复杂度：空间复杂度一方面取决于栈的深度，另一方面我们需要记录board的访问。 因此空间复杂度为 $O(M * N)$



欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)