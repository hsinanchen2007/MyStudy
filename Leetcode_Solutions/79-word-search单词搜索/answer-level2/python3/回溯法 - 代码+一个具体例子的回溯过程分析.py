### 解题思路

在每个点都能向上下左右四个方向搜索。

但是注意，不能回到已经搜索过的地方，所以定义了 mp 记录所有点是否已经搜索过了。
否则会出现如：
```python
[['A', 'B']], 'ABA' 
```
```python
[['A', 'B'],
 ['D', 'C']]
'ABCDA' 
```
这种被认为是 True

可以看一个具体的例子的搜索过程：
```python
[["A","B","C","E"],
 ["S","F","E","S"],
 ["A","D","E","E"]],
"ABCESEEEFS"
```

```c++
0 0 A
		 0 1 B
			 0 2 C
				 0 3 E
					 1 3 S
						 1 2 E
							 2 2 E
								 2 3 E
backtrack
backtrack
backtrack
						 2 3 E
							 2 2 E
								 1 2 E
									 1 1 F
										 1 0 S
```
开始是从 左上 沿着第一行一直到 右上，再到第二行最右的 S，这时候没有继续向下，而是先往左了，这导致后面搜到三个 E，就到角落里了，所以这里出现了回溯，退回了三步，还是回到了这个 S，从这里往下走，才能找到最终的答案。


### 代码

```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(board)
        m = len(board[0])
        def dfs(i, j, index):
            mp[i][j] = False
            #print('\t' * index, i, j, word[index-1])
            if index == len(word):
                return True
            for ii, jj in [(0,1),(0,-1),(1,0),(-1,0)]:
                if 0 <= i + ii < n and 0 <= j + jj < m and board[i+ii][j+jj] == word[index] and mp[i+ii][j+jj]:
                    if dfs(i+ii, j+jj, index + 1):
                        return True
            #print('backtrack')
            mp[i][j] = True
            return False
        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0]:
                    mp = [[True] * m for i in range(n)]
                    if dfs(i, j, 1):
                        return True
        return False
```

欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)