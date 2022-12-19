### 解题思路
考察深度优先搜索算法（Depth First Search，简称DFS）
1、在进入DFS前，设置temp变量记录board[i][j]原来的值，然后把board[i][j]的值原地改为' '
2、等从DFS出来后，再把board[i][j]改回原来的值
3、这样就可以避免重复进入
4、因为是原地修改，避免了辅助变量，开销较小


### 代码

```python
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
      
        # 第一种方法，递归法
        # zip([1,2,3],['a','c','b'])得到 ((1,'a'),(2,'c'),(3,'b))
        def dfs(i, j, k):
            if board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True
            board[i][j] += ' '
            for p, q in zip((i-1, i+1, i, i), (j, j, j-1, j+1)):
                if 0 <= p < m and 0 <= q < n:
                    if dfs(p, q, k+1):
                        return True
            board[i][j] = board[i][j][0]
            return False

        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False

        # 第二种方法，非递归方法待改正，浪费了存储空间

        # m=len(board)
        # if m==0:
        #     return False
        # n=len(board[0])
        # if n==0:
        #     return False
        # sign_matrix_dict={}
        # word_len=len(word)
        # pos=0
        # for i in range(m):
        #     if i not in sign_matrix_dict:
        #         sign_matrix_dict[i]={}
        #     for j in range(n):
        #         sign_matrix_dict[i][j]=0

        # i=0
        # j=0
        # for i in range(m):
        #     for j in range(n):
        #         while(pos<word_len):
        #             sign=0
        #             if word[pos]==board[i][j] and sign_matrix_dict[i][j]==0:
        #                 sign_matrix_dict[i][j]=1
        #                 pos=pos+1

        #             if i-1>=0 and j>=0 and sign_matrix_dict[i-1][j]==0:
        #                 if word[pos]==board[i-1][j]:
        #                     sign_matrix_dict[i-1][j]=1
        #                     pos=pos+1
        #                     i=i-1
        #                     j=j
        #                     sign=1   
        #             elif i+1<m and j>0:
        #                 if word[pos]==board[i+1][j]:
        #                     sign_matrix_dict[i+1][j]=1
        #                     pos=pos+1
        #                     i=i+1
        #                     j=j
        #                     sign=1
        #             elif i<m and j-1>=0:
        #                 if word[pos]==board[i][j-1]:
        #                     sign_matrix_dict[i][j-1]=1
        #                     pos=pos+1
        #                     i=i
        #                     j=j-1
        #                     sign=1
        #             elif i<m and j+1<n:
        #                 if word[pos]==board[i][j+1]:
        #                     sign_matrix_dict[i][j+1]=1
        #                     pos=pos+1
        #                     i=i
        #                     j=j+1
        #                     sign=1

        #             if sign==0:
        #                 sign_matrix_dict[i][j]=0
        #                 pos=pos-1
        #             if pos==-1:
        #                 pos=0
        #             if pos==word_len:
        #                 return True
        # return False
```