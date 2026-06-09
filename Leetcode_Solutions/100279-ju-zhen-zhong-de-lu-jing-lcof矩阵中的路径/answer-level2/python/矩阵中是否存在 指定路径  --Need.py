### 解题思路
1. **注意代码细节即可，没有任何技巧可言**
    - 上下左右，visit 记录位置，回退时，记得复原
    - **dfs 的开始条件是 board[i][j] == word[0]**
2. [面试题12. 矩阵中的路径（深度优先搜索 DFS ，清晰图解）](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/mian-shi-ti-12-ju-zhen-zhong-de-lu-jing-shen-du-yo/)
    - 讲解的非常详细

### 代码

```python3
class Solution:

    def exist(self, board: List[List[str]], word: str) -> bool:
        
        nsize = len(board)
        if nsize < 1:
            return False
        
        msize = len(board[0])

        v = [[0] * msize for i in range(nsize)]

        for i in range(nsize):
            for j in range(msize):
                if board[i][j] == word[0]:
                    v[i][j] = 1
                    p = 1
                    res = self.judge(board, v, word, i, j, p, nsize, msize)
                    if res:
                        return True 
                    v[i][j] = 0
        
        return False 

    
    def judge(self, a, v, s, i, j, p, nsize, msize):
        if len(s) == p:
            return True
        
        for idx, jdx in [(-1,0),(1,0), (0,1), (0,-1)]:
            inext, jnext  = idx + i, jdx + j 
            #if inext >= 0 and inext < nsize and jnext >=0 and jnext < msize and v[inext][jnext] == 0 and  a[inext][jnext] = s[p]:       
            if inext >= 0 and inext < nsize and jnext >= 0 and jnext < msize and v[inext][jnext] == 0 and a[inext][jnext] == s[p]:  ## right...
                v[inext][jnext] = 1
                p += 1
                res = self.judge(a, v, s, inext, jnext, p, nsize, msize)
                if res :
                    return res
                ## false  need reset 0 
                p -= 1
                v[inext][jnext] = 0
                
        
        return False
```