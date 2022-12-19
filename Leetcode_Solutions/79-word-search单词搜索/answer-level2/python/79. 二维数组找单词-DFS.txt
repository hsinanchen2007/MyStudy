![image.png](https://pic.leetcode-cn.com/8c5b79a77d135a12e6c10581a746abe174891b9e6c74dbf081d6eacc88443f26-image.png)

### 解题思路
和岛屿dfs类似，为了找到单词匹配，遍历每个元素；
对每个元素进行4个方向的dfs。

但要注意：
1）用过的不能再用，可以修改字符 + 返回时修改回去
2）当一个方向True了后，可以直接返回True了，不必再考虑其他方向；
3）同理有一个元素打头成功了，后面的也可以不管了。


### 代码

```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        def dfs(i, j, word):
            if not word:
                return True

            if 0 <= i < len(board) and 0 <= j < len(board[0]) and board[i][j] != 0 and board[i][j] == word[0]:
                tmp = board[i][j]
                board[i][j] = 0
                if dfs(i, j+1, word[1:]):
                    return True
                if dfs(i+1, j, word[1:]):
                    return True
                if dfs(i-1, j, word[1:]):
                    return True
                if dfs(i, j-1, word[1:]):
                    return True
                board[i][j] = tmp
                return False
            else:
                return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, word):
                    return True
        return False

```