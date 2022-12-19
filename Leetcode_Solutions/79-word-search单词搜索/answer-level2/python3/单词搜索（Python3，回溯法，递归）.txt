
![word_resarch.png](https://pic.leetcode-cn.com/9941cf3e7d7e8148bb26056d7df51adaa017183013e2524e4c5f5b32de5f2d67-word_resarch.png)
**路径**：搜索的过程中有几种限制，i代表行，j代表列，二维网格m*n：
1. i=0时，不可以向上走
2. i=m-1时，不可以向下走
3. j=0时，不可以向左走
4. j=n-1时，不可以向右走

算法过程描述：
step=0，step记录网格匹配word的个数
迭代二维网格board，字母board[i][j]：
    if board[i][j]==word[step] 则step+=1
    调用backtrace函数
        递归出口：当step==len(ch)
            设置self.exit=1,self.flag=1
            退出递归体
        递归体：
            反复执行**路径**，递归搜索单词
            若满足其中一种路径条件，对step+=1,更新行列坐标
若flag==1且无环出现，则返回搜索成功
否则返回搜索失败
```
class Solution:
    def __init__(self):
        #flag默认为0表示没有这个单词
        self.flag = 0
        #将每个字符的行列坐标存到array中
        self.array = []
        #搜索到单词，退出递归
        self.exit = 0
    def exist(self, board: List[List[str]], word: str) -> bool:
        def backtrace(m,step,i,j,ch):
            #搜索成功
            if step==len(ch):
                self.flag = 1
                self.exit = 1
                self.array = [i for i in save_index]
            #退出递归
            if self.exit==1:
                return
            #上下左右搜索单词
            if step!=len(ch) and self.exit==0:
                #上
                if i>0 and m[i-1][j]==ch[step]:
                    temp = m[i][j]
                    m[i][j]='1'
                    if [i,j] not in save_index:
                        save_index.append([i,j])
                    state = backtrace(m,step+1,i-1,j,ch)
                    if state==False:
                        save_index.pop()
                    m[i][j]=temp
                #下
                if i<len(m)-1 and m[i+1][j]==ch[step]:
                    temp = m[i][j]
                    m[i][j]='1'
                    if [i,j] not in save_index:
                        save_index.append([i,j])
                    state =  backtrace(m,step+1,i+1,j,ch)
                    m[i][j]=temp
                    if state==False:
                        save_index.pop()
                #左
                if j>0 and m[i][j-1]==ch[step]:
                    temp = m[i][j]
                    m[i][j]='1'
                    if [i,j] not in save_index:
                        save_index.append([i,j])
                    state = backtrace(m,step+1,i,j-1,ch)
                    if state==False:
                        save_index.pop()
                    m[i][j]=temp
                #右
                if j<len(m[0])-1 and m[i][j+1]==ch[step]:
                    temp = m[i][j]
                    m[i][j]='1'
                    if [i,j] not in save_index:
                        save_index.append([i,j])
                    state = backtrace(m,step+1,i,j+1,ch)
                    if state==False:
                        save_index.pop()
                    m[i][j]=temp
                    
                return False
        save_index = []
        step = 0
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if word[0]==board[i][j]:
                    backtrace(board,step+1,i,j,word)
                    if self.flag == 1 and len(self.array) == len(word)-1:
                        return True
                else:
                    continue
        return False
                
```
