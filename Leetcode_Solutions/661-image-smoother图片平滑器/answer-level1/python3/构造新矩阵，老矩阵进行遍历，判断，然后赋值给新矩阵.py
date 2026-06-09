class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        self.M = M
        N = [[0]*(len(M[0])) for i in range(len(M))]
        
        for i in range(len(M)):
            for j in range(len(M[0])):
                num=0
                sum=0
                # print(i,j)
                for a in range(i-1,i+2,1):
                    for b in range(j-1,j+2,1):
                        if (0<=a<=(len(M))-1) and (0<=b<=(len(M[0])-1)):
                            num = num+1
                            sum = sum + M[a][b]
                avg= sum//num
                N[i][j]=avg
                                
        return N