### 解题思路
此处撰写解题思路
使用额外的状态想到了，但是没想到官方的那个就是使用两个额外的状态，
如果细胞之前的状态是 0，但是在更新之后变成了 1，我们就可以给它定义一个复合状态 2。这样我们看到 2，既能知道目前这个细胞是活的，还能知道它之前是死的。
如果细胞之前的状态是 1，但是在更新之后变成了 0，我们就可以给它定义一个复合状态 -1。这样我们看到 -1，既能知道目前这个细胞是死的，还能知道它之前是活的。

额外状态记录这里自己还需要磨练，个人用的方法就是，字典记录下所以需要改变状态的位置，和改变成什么状态，然后直接用这个字典遍历修改原始board，
只是如果这个字典算出来很大的化，空间复杂度也很不好，只能说比复制一份要好一点把。但是没有两个额外状态的好。

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m,n = len(board),len(board[0])
        def neighbour(i,j):
            for r,c in ((i-1,j),(i+1,j),(i,j-1),(i,j+1),(i-1,j-1),(i+1,j+1),(i-1,j+1),(i+1,j-1)):
                if 0<=r<m and 0<=c<n:
                    yield (r,c)
        
        def helper(i,j):
            ans = 0
            for r,c in neighbour(i,j):
                if board[r][c]==1:
                    ans+=1
            return ans

        change = {}

        for i in range(m):
            for j in range(n):
                num = helper(i,j)
                if board[i][j]==1 and num not in (2,3):
                    change[(i,j)]=0
                if board[i][j]==0 and num==3:
                    change[(i,j)]=1
        for k,v in change.items():
            i,j=k
            board[i][j]=v


                    

```