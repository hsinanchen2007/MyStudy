### 解题思路
思路，原地修改的前提是，数字特征值记录迭代前死活，本人的思路是校验奇偶，即定义：
活->活 1->1
活->死 1->3
死->活 0->2
死->死 0->0
只有死活转换的时候需要改变board值，也就是说：
board以前是活的时候，需要判断现在是否要死过去
board以前是死的时候，需要判断现在是否要活过来
检查原状态的时候，只需要%2即可知道原状态，&1和%2效果一样
计数函数，遍历九个格子，不能越界，不能原地比较：不能ij同时为0

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        n,m=len(board),len(board[0])
        for i in range(n):
            for j in range(m):
                C=0
                for x in (-1,0,1):
                    for y in (-1,0,1):
                        if(x or y)and 0<=i+x<n and 0<=j+y<m and board[x+i][j+y]&1:C+=1
                if board[i][j]&1 and(C<2 or C>3):board[i][j]=3
                if board[i][j]&1==0 and C==3:board[i][j]=2
        for i in range(n):
            for j in range(m):
                board[i][j]=int(0<board[i][j]<3)
```