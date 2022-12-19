#可能我个人问题：一个是列表复制（不是同一地址的） 一个是注意循环中的列表的改变
class Solution:
    def orangesRotting(self, grid) -> int:
        count=0
        n_count=0
        o_count=0
        #初始化新鲜和腐烂的水果数
        #mid=[grid[i][j] for i in range(len(grid)) for j in range(len(grid[0]))]
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if(grid[i][j]==1):
                    n_count+=1
                if(grid[i][j]==2):
                    o_count+=1
        if(o_count==0 and n_count!=0):
            return -1
        #四个方向循环遍历
        mid=[grid[i][:] for i in range(len(grid))]
        while(n_count != 0):
            before=n_count
            grid = [mid[i][:] for i in range(len(grid))]
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    if(grid[i][j]==2):
                        if(i-1 >=0 and mid[i-1][j] == 1):
                            mid[i-1][j]=2
                            n_count-=1
                        if(j-1 >=0 and mid[i][j-1] == 1):
                            mid[i][j-1]=2
                            n_count-=1
                        if(i+1 < len(grid) and mid[i+1][j] == 1):
                            mid[i+1][j]=2
                            n_count-=1
                        if(j+1 < len(grid[0]) and mid[i][j+1] == 1):
                            mid[i][j+1]=2
                            n_count-=1
            #要避免不会腐烂的水果
            if(before == n_count):
                return -1
            count+=1
        return count