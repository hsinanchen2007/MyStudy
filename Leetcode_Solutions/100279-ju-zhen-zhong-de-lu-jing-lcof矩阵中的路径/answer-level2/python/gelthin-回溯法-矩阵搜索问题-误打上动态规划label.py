### 解题思路
这题应该是 回溯法，却被打上 动态规划的标签，错误！

同习题 [主站79 题](https://leetcode-cn.com/problems/word-search/)


参看了题解 [面试题12. 矩阵中的路径（深度优先搜索 DFS ，清晰图](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/mian-shi-ti-12-ju-zhen-zhong-de-lu-jing-shen-du-yo/)
其提到， 本题是典型的矩阵搜索问题



回溯法一直没有好好练过，确实吃亏。



### 代码

```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # 回溯法，dfs 一直没有练过相关题目
        def dfs(i, j, k):
            if not (0<=i<m) or not (0<=j<n) or board[i][j] != word[k]:
                return False
            tmp, board[i][j] = board[i][j], '/'
            if k+1 == len(word):
                return True
            else:
                res = dfs(i+1, j, k+1) or dfs(i-1, j, k+1) or dfs(i, j+1, k+1) or dfs(i, j-1, k+1)
                board[i][j] = tmp
                return res
        
        m = len(board)
        if m==0:
            return False
        n = len(board[0])

        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False
```