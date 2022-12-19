```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m,n=len(board),len(board[0])
        if m==0: return False
        marked=[[False for _ in range(n)]for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if self.search_word(board,word,0,i,j,marked,m,n):
                    return True
        return False
    directions=[(0,1),(0,-1),(-1,0),(1,0)]
    def search_word(self,board,word,index,x,y,marked,m,n):
        if index==len(word)-1:
            return board[x][y]==word[index]
        if board[x][y]==word[index]:
            marked[x][y]=True
            for direction in self.directions:
                new_x=x+direction[0]
                new_y=y+direction[1]
                if 0<=new_x<m and 0<=new_y<n and not marked[new_x][new_y] and \
                    self.search_word(board,word,index+1,new_x,new_y,marked,m,n):
                    return True
            marked[x][y]=False
        return False
```
