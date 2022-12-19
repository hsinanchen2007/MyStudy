从海洋边界向陆地搜索，否则会超时。。。这点要注意。找到所有连接大西洋和太平洋的路径。   

还有此题有个地方没说清楚，边界的水流是可以直接流入相临的洋的。所以n 0 和 0 m 两个对角是必流通的。
```
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
    
        if(not matrix):
            return []
        n,m = len(matrix),len(matrix[0])
        
        connect_taipingyang = [[0] * m for _ in range(n)]
        connect_daxiyang = [[0] * m for _ in range(n)]
        for i in range(n):
            self._dfs(matrix,i,0,connect_taipingyang)
            self._dfs(matrix,i,len(matrix[0]) - 1,connect_daxiyang) 
        for j in range(m):
            self._dfs(matrix,0,j,connect_taipingyang)
            self._dfs(matrix,len(matrix) - 1,j,connect_daxiyang)
        ret = []
        
        for i in range(n):
            for j in range(m):
                if(connect_taipingyang[i][j] and connect_daxiyang[i][j]):
                    ret.append([i,j])
        
        return ret
        
    def _dfs(self,matrix,i,j,connect):
        
        connect[i][j] = 1
        
        for pos1,pos2 in ((1,0),(-1,0),(0,1),(0,-1)):
            
            if(i+pos1 < 0 or j + pos2 < 0 or i + pos1 > len(matrix) - 1 or j + pos2 > len(matrix[0]) - 1 or connect[i+pos1][j + pos2] == 1):
                continue
            
            if(matrix[i+pos1][j+pos2] >= matrix[i][j]):
                self._dfs(matrix,i+pos1,j+pos2,connect)
            
```
