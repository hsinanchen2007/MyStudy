class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for l in board:
            if "R" in l:
                a = board.index(l)
                b = l.index("R")
                break

        k = 0
        rows = len(board)
        cols = len(board[0])

        for i in range(b,-1,-1):
            
            if board[a][i] == "B":
                break
            if board[a][i] == "p":
                k += 1
                break
        #print(k)

        for i in range(b,cols):
            
            if board[a][i] == "B":
                break
            if board[a][i] == "p":
                k += 1
                break
        #print(k)
        
        for i in range(a,-1,-1):
            print(board[i][b])
            if board[i][b] == "B":
                break
            if board[i][b] == "p":
                k += 1
                break
        #print(k)

        for i in range(a,rows):
            if board[i][b] == "B":
                break
            if board[i][b] == "p":
                k += 1
                break
        #print(k)
        return k