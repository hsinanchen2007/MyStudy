### 解题思路
思路：
1.统计每个细胞周围八个位置的细胞的情况，得到活细胞的个数。
```
        for i in range(m):
            for j in range(n):
                ns = []
                for i_step, j_step in [-1,-1], [0,-1],[1,-1], [-1,0], [1,0], [-1,1], [0,1], [1,1]:
                    if 0 <= i_step+i < m and 0 <= j_step+j < n:                       
                        ns.append(board[i_step+i][j_step+j])
                ns_sum = sum(ns)
```
2.根据条件筛选出需要改变生命状态的细胞所在的位置。
```
        if board[i][j] == 0 and ns_sum == 3:
            location.append([i,j])
        elif board[i][j] == 1:
                if ns_sum < 2 or ns_sum > 3:
                location.append([i,j])
```
3.将这些位置的值与1做异或操作
```
        for i, j in location:
            board[i][j] = board[i][j]^1 
```

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        location = []
        for i in range(m):
            for j in range(n):
                ns = []
                for i_step, j_step in [-1,-1], [0,-1],[1,-1], [-1,0], [1,0], [-1,1], [0,1], [1,1]:
                    if 0 <= i_step+i < m and 0 <= j_step+j < n:                       
                        ns.append(board[i_step+i][j_step+j])
                ns_sum = sum(ns)
                if board[i][j] == 0 and ns_sum == 3:
                    location.append([i,j])

                elif board[i][j] == 1:
                     if ns_sum < 2 or ns_sum > 3:
                        location.append([i,j])
        for i, j in location:
            board[i][j] = board[i][j]^1 
        
        

```