（速度和空间都不咋地- =）
首先用start储存开头的字母的coordinates，如果不存在，直接返回False；
然后开始回溯，其中有两点是我debug了好久才搞明白的（菜鸡一个- =）：
1. 要有判断条件if backtrack(): return True, 否则return之后会继续往后面搜索，并且整个backtrack输出的结果一直是None
2. 如果backtrack未返回true，要unmark刚才的路径经过的点，否则会影响后续路径的选择。想象一下：第一条路走了6步能成功，但最后一步失败了，第二条路的某三步和第一条路相同，如果第一条路失败后直接退回不unmark的话，第二条路就无法走和第一条路交叉的三补了。
代码块
    if 0 <= ii < row and 0 <= jj < col and marked[ii][jj] != 1:
        if board[ii][jj] == word[move + 1]:
            #print(word[move + 1])
            #print(ii, jj)
            marked[ii][jj] = 1
            if backtrack((ii, jj), move + 1, marked): 
                return True
            else:
                marked[ii][jj] = 0
总的代码是这样的：
```
def exist(board, word):
    row = len(board)
    col = len(board[0])
    start = []
    for i in range(row):
        for j in range(col):
            if board[i][j] == word[0]:
                start.append((i, j))
    
    if not start:
        return False
    #print(start)
   
    
    def backtrack(coordinate, move):
        
        if move == len(word)-1:
            
            return True
        
            
        i, j = coordinate[0], coordinate[1]
        
        for x, y in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            
            ii = i + x
            jj = j + y
            #print(board[ii][jj])
            if 0 <= ii < row and 0 <= jj < col and marked[ii][jj] != 1:
                if board[ii][jj] == word[move + 1]:
                    #print(word[move + 1])
                    #print(ii, jj)
                    marked[ii][jj] = 1
                    if backtrack((ii, jj), move + 1): 
                        return True
                    else:
                        marked[ii][jj] = 0
   

    for s in start:
        marked = [[0 for _ in range(col)] for _ in range(row)]
        marked[s[0]][s[1]] = 1
        sol = backtrack(s, 0)
        #print('res = ', sol)
        if sol:
            return True
            break
    return False

if __name__ == "__main__":
     
    board = [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
     
    word = "ABCESEEEFS"
    
    print(exist(board, word))
```
