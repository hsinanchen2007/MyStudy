### 解题思路
如果我们直接在原数组上面更新状态，那么会造成异步更新的问题

所以比较容易想到的办法就是新拷贝一个数组来逐个更新，下面这份代码就是

挑战是原地完成，思路是这样的，我们可以用状态2来表示细胞是活的，但是它是由一个死状态更新来的。用状态-1来表示细胞是死的，但是它是由活细胞更新来的。

之所以这样设置，是因为在判断的时候，我们可以用abs()==1 来判断它以前是否为活细胞

这样可以节省空间在原地完成，但是代价是最后需要再便利一遍数组，把2状态变成1，把-1状态变成0
### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # 非原地算法
        def count(board,c1,c2,k1,k2,cur1,cur2):
            ans = 0
            for i in range(c1,c2+1):
                for j in range(k1,k2+1):
                    if(i == cur1 and j == cur2):
                        continue
                    if board[i][j] == 1:
                        ans += 1
            
            return ans 
        m = len(board)
        n = len(board[0])
        new = [[1 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                c1 = max(i-1,0)
                c2 = min(i+1,m-1)
                k1 = max(j-1,0)
                k2 = min(j+1,n-1)
                alive = count(board,c1,c2,k1,k2,i,j)
                if board[i][j] == 1:
                    if alive < 2 or alive>3:
                        new[i][j] = 0
                if board[i][j] == 0:
                    if alive != 3:
                        new[i][j] = 0
        
        board[:] = new[:]
        
        return new
```