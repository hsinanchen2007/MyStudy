# 题解
## 回溯
 1. 初始化行数$m$，列数$n$，$word$长度$l$以及访问数组$visited$为$m*n$数组，初始化为$False$。
 2. 定义回溯函数$track\_back(i,j,k)$，$i,j$表示当前访问的数组$board$的位置索引。$k$表示正在和$word$匹配的位置。
 	* 若$k==l-1$，说明此时访问到$word$最后一个位置，返回此时数组$board[i][j]$是否等于$word$最后一个字母。
 	* 若当前$board[i][j]$等于$word[k]$，则：
 		+ 令$visited[i][j]=True$
 		+ 对当前位置的上下左右四个位置继续进行递归，令$new\_i=i+x,new_j=j+y$，若$0<=new\_i<m\ and\ 0<=new\_j<n\ and\ not\ visited[new\_i][new\_j]\ and\ track\_back(new\_i,new\_j,k+1)$ 。则返回$True$。表示下一访问位置在$board$范围内，且未被访问，且后续可以匹配成功。
 		+ 若执行完，则说明没有匹配成功，则令$visited[i][j]$重新置为$False$，以便在其他位置遍历时继续使用。
 	* 返回$False$
 3. 对$board$中每一个位置，都判断一次
 4. 若执行完，无返回，则返回$False$。

### 复杂度分析
 - 时间复杂度：$O(n!)$。
 - 空间复杂度：$O(n)$

### Python

```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if(not board or not board[0]):
            return False
        m=len(board)
        n=len(board[0])
        l=len(word)
        visited=[[False]*n for _ in range(m)]
        def track_back(i,j,k):
            if(k==l-1):
                return board[i][j]==word[k]
            if(board[i][j]==word[k]):
                visited[i][j]=True
                for x,y in [[-1,0],[1,0],[0,1],[0,-1]]:
                    new_i,new_j=i+x,j+y
                    if(0<=new_i<m and 0<=new_j<n and not visited[new_i][new_j] and track_back(new_i,new_j,k+1)):
                        return True
                visited[i][j]=False
            return False
        
        for i in range(m):
            for j in range(n):
                if(track_back(i,j,0)):
                    return True
        return False
```