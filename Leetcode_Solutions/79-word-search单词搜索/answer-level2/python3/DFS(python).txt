主要思路是回溯法（涉及**深度搜索**、**剪枝**、**状态重置**，其中细节也蛮多）先贴代码，然后再讲解
```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if len(board)==0: return False
        def neighbor(i,j):
            q=[]
            if i-1>=0: q.append((i-1,j))
            if i+1<m: q.append((i+1,j))
            if j-1>=0: q.append((i,j-1))
            if j+1<n: q.append((i,j+1))
            return q
        def search(i,j,word,index):
            if index==len(word): # 递归结束条件
                return True
            for loc in neighbor(i,j):
                l=loc[0]; k=loc[1]
                if (l,k) not in used and board[l][k]==word[index]:
                    used.append((l,k)) # 已走过位置加入状态集
                    if search(l,k,word,index+1):
                        return True # 剪枝，从此一路返回，后面所有的节点都不在搜寻
                    used.remove((l,k)) # 如果没有执行上一行，代表没有发生剪枝，也就是当前节点的所有下一步节点均不满足，那么这条分支也就自然不满足，
                                       # 去除该节点，以后的分支可能会继续使用
            return False # 代表搜寻完所有可能分支均没有找到满足条件
                
        m = len(board)
        n = len(board[0])
        used = []
        for i in range(m):
            for j in range(n):
                if board[i][j]==word[0]:
                    used.append((i,j))
                    flag = search(i,j,word,1)
                    if flag: return True
                    used.remove((i,j))
        return False
                    
```
函数neighbor实现寻找邻居功能，也就是当前位置所有可选的相邻位置，也就是所有分支
函数search实现搜寻功能,递归结束的时候一路返回True,实现剪枝的功能,注意区分递归结束的时候也就是剪枝的时候，这是和其他题目有点区别的地方
利用一个双层循环找到任何一个可能的进入节点，如果连初始进入节点都找不到，就返回False
