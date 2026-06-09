### 解题思路
算法在执行用时上击败99%的用户
思路很简单，先写一个搜索函数，该函数的功能就是从当前位置的四周进行搜索，然后递归执行该函数，当搜索串等于word时返回True，层层返回。
其中：
flag为搜索痕迹（被搜索的位置记1）。S为当前搜索串。i，j为当前搜索位置。

### 代码

```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        flag=[]
        for i in range(len(board)):
            flag.append([])
            for j in range(len(board[0])):
                flag[i].append(0)
        def search(board,flag,word,S,i,j):
            if word==S:
                return True
            side=[]
            if i-1>=0 and flag[i-1][j]==0:side.append([i-1,j])
            if i+1<len(board) and flag[i+1][j]==0:side.append([i+1,j])
            if j-1>=0 and flag[i][j-1]==0:side.append([i,j-1])
            if j+1<len(board[0]) and flag[i][j+1]==0:side.append([i,j+1])
            if len(side)==0:
                return False
            for p,q in side:
                if board[p][q]==word[len(S)]:
                    flag[p][q]=1
                    if search(board,flag,word,S+word[len(S)],p,q):
                        return True
                    flag[p][q]=0
            else:
                return False

        start=[]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]==word[0]:
                    start.append([i,j])
        if len(start)==0:
            return False
        else:
            for i,j in start:
                flag[i][j]=1
                if search(board,flag,word,word[0],i,j):
                    return True
                flag[i][j]=0
        return False
```
