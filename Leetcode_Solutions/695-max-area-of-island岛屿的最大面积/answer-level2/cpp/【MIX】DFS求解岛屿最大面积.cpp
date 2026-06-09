```java []
class Solution {
    private int R,C;
    private int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    private boolean[][] visited;
    private int[][] grid;
    public int maxAreaOfIsland(int[][] grid) {
        R = grid.length;
        C = grid[0].length;
        this.grid = grid;
        if(R<=0 || C<=0)
            return 0;

        visited = new boolean[R][C];
        
        int res = 0;
        for(int i=0; i<R; ++i)
            for(int j=0; j<C; ++j)
                if(grid[i][j] == 1 && !visited[i][j]){
					// 使用参数的方法进行递归
                    res = Math.max(res, dfs(i*C+j, 0));
                }
    
        return res;
    }

    private int dfs(int v, int area){
        int x = v/C;
        int y = v%C;
        visited[x][y] = true;    
        ++area;
    
        for(int []d : dirs){
            int new_x = x+d[0];
            int new_y = y+d[1];

            if(inArea(new_x, new_y) && !visited[new_x][new_y] && grid[new_x][new_y]==1){
                // area = Math.max(area, dfs(new_x*C+new_y, area));
                area = dfs(new_x*C+new_y, area);
            }
        }
        return area;
    }

    private boolean inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }
}
```
```python []
class Solution:
	# 四连通方向
	dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
		# 提取图像信息
		self.R = grid.__len__()
		self.C = grid[0].__len__()
		
		# 数值合法性判定
		if self.R == 0:
			return 0
		if self.C == 0:
			return 0

		# 初始化访问数组
		self.visited = [[False for _ in range(self.C)] for _ in range(self.R)]
		self.grid = grid
		res = 0

		for i in range(self.R):
			for j in range(self.C):
				if self.visited[i][j] == False and grid[i][j] == 1:
					res = max(res, self.dfs(i, j))
		return res

	
	# DFS遍历
	def dfs(self, x:int, y:int) -> int:
		self.visited[x][y] = True
		res = 1
		for d in self.dirs:
			new_x = x + d[0]
			new_y = y + d[1]
			if inArea(new_x, new_y) and self.visited[new_x][new_y]==False and self.grid[new_x][new_y]==1:
				res += self.dfs(new_x, new_y)
		return res

	# 顶点合理性判定
	def inArea(self, x:int, y:int) -> bool:
		return 0<= x <self.R and 0<= y < self.C
```
```c++ []
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		this->R = grid.size();
		this->C = grid[0].size();
		this->grid = grid;
		this->visited = vector<vector<bool>>(R, vector<bool> (C, false));
		// 存储计算面积
		int res = 0;

		// 对陆地部分进行遍历探测
		for(int i=0; i<R; ++i)
			for(int j=0; j<C; ++j)
				if(!visited[i][j] && grid[i][j]==1)
					res = max(res, dfs(i, j));
		return res;
	}

// 定义私有函数
private:
	int dfs(int x, int y){
		visited[x][y] = true;
		int res = 1;
		for(vector<int> d: dirs){
			int new_x = x + d[0];
			int new_y = y + d[1];
			if(inArea(new_x, new_y) && !visited[new_x][new_y] && grid[new_x][new_y]==1)
				res += dfs(new_x, new_y);
		}
		return res;
	}

	bool inArea(int x, int y){
		return 0<= x && x< R && 0<=y && y< C;
	}


// 定义私有变量
private:
	vector<vector<int>> grid;
	int R;
	int C;
	vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	vector<vector<bool>> visited;
};
```
