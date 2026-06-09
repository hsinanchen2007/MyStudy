class Solution:
    def generateMatrix(self, n: int) :
        res=[[ i+j*n for i in range(n)] for j in range(n)]
        output = [[0]*n for _ in range(n)]
        check_line= []
        while res:
            check_line += res.pop(0)
            res = list(map(list,zip(*res)))[::-1]
        for i in range(n**2):
            x,y=divmod(check_line[i],n)
            output[x][y] = i+1
        return output