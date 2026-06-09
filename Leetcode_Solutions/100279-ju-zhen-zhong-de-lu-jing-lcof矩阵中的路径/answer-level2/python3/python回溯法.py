```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def fun(x,y,i,temp): #x和y是board的坐标，i是word的索引，temp是一个存储已走过路径的set
            if i==len(word):
                return True
            if 0<=x<len(board) and 0<=y<len(board[0]) and (x,y) not in temp and board[x][y]==word[i]:
                return fun(x-1,y,i+1,temp|{(x,y)}) \
                        or fun(x+1,y,i+1,temp|{(x,y)}) \
                        or fun(x,y-1,i+1,temp|{(x,y)}) \
                        or fun(x,y+1,i+1,temp|{(x,y)})
            return False
        for x in range(len(board)):
            for y in range(len(board[0])):
                if fun(x,y,0,set()):
                    return True
        return False

```
