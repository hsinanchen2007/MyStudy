
    def rotate(self, matrix: List[List[int]]) -> None:
        n=len(matrix)-1
        for i in range((len(matrix)+1)//2):
            for j in range(i,len(matrix)-i-1):
                matrix[i][j],matrix[j][n-i],matrix[n-i][n-j],matrix[n-j][n-(n-i)]=matrix[n-j][n-(n-i)],matrix[i][j],matrix[j][n-i],matrix[n-i][n-j]
