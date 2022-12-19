import math

class Solution:
    def maxDistance(self, grid) :
        water=[] # 0
        land=[]  # 1
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]==0:
                    water.append([i,j])
                else:
                    land.append([i,j])
        if len(water)==0 or len(land)==0:
            return -1
        tempres=[]
        mark=[]
        for i in water:
            max_dist=math.inf
            for j in land:
                temp=self.ManhattanDistance(i,j)
                if temp<max_dist:
                    mark=j
                    max_dist=temp
            tempres.append([mark,max_dist])
        min_dist=max([i[1] for i in tempres])
        return min_dist


    def ManhattanDistance(self,x,y):
        return int(abs(x[0]-y[0])+abs(x[1]-y[1]))

if __name__ == "__main__":
    #s=[[1,0,1],[0,0,0],[1,0,1]]
    s=[[1,0,0],[0,0,0],[0,0,0]]
    so=Solution()
    print(so.maxDistance(s))

    