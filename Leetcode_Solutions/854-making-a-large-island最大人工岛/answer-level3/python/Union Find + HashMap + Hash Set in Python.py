Union Find with HashMap
先使用dfs查找同一个岛屿上的所有点，然后利用`father`的HashMap来实现同一个岛屿的点都指向第一个进入DFS的岛屿位置。同时使用一个`size`的HashMap来存储每一个岛屿的大小，HashMap的key就是之前同一个岛屿所有的点指向的father。
然后对每一个海洋进行遍历，访问海洋四周的点，利用hashset来保证每个岛屿的father只出现一次。
最后打擂台找到最大的联通岛屿。
```
class Solution(object):
    def largestIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        seas = []
        self.father = {}
        self.size = {}
        self.delta = [(1,0),(0,1),(0,-1),(-1,0)]
        self.visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
        for index_x in range(len(grid)):
            for index_y in range(len(grid[0])):
                if grid[index_x][index_y] ==0:
                    seas.append((index_x,index_y))
                if self.visited[index_x][index_y]:
                    continue
                if grid[index_x][index_y] == 1:
                    self.dfs(index_x,index_y,grid)
        ret = 0
        if len(seas) in [0,1]:
            return len(grid)*len(grid[0])
        for sea_x , sea_y in seas:
            tmp , tmp_list = 1 , set()
            for delta_x , delta_y in self.delta:
                fut_x , fut_y = delta_x + sea_x , delta_y + sea_y
                if 0 <= fut_x < len(grid) and 0 <= fut_y < len(grid[0]) and grid[fut_x][fut_y] == 1:
                    father = self.father[(fut_x,fut_y)]
                    if father not in tmp_list:
                        tmp += self.size[father]
                        tmp_list.add(father)
            ret = max(ret , tmp)
        return ret
                    
                    
    def dfs(self,x,y,grid):
        length_x , length_y = len(grid) , len(grid[0])
        stack = collections.deque([(x,y)])
        self.size[(x,y)] = 0
        while stack:
            cur_x , cur_y = stack.popleft()
            if self.visited[cur_x][cur_y]:
                continue
            self.visited[cur_x][cur_y] = True
            self.size[(x,y)] += 1
            self.father[(cur_x,cur_y)] = (x,y)
            for delta_x , delta_y in self.delta:
                if 0 <= delta_x + cur_x < length_x and 0 <= delta_y + cur_y < length_y and grid [delta_x + cur_x][delta_y + cur_y] == 1:
                    stack.append((cur_x + delta_x,cur_y + delta_y))
        
            
        
```