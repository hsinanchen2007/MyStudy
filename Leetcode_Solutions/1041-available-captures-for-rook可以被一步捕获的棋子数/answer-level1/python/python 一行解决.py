### 解题思路
开头申明，用一行过每日一题是一种兴趣爱好，不是良好的代码习惯，对应试也没有帮助，不喜勿喷。
这题比较简单就不分析了，代码的思想就是将二维数组摊开成一条字符串之后，删除其中的'.'，再搜索其中的'pR'和'Rp'即可，写的有点繁琐，不知道有没有更优雅的解决方案。

### 代码

```python
class Solution(object):
    def numRookCaptures(self, board):
        return (lambda x:x('pR')+x('Rp'))([''.join(board[x]+[' ']+[i[y] for i in board]).replace('.','') for x in range(8) for y in range(8) if board[x][y]=='R'][0].count)
```