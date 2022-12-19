### 解题思路
构造并查集, 使用BFS求解

### 代码

```c++ []
class Solution {

private:
    class UnionFind{
    public:
        UnionFind(int R, int C){
            for(int i=0; i<R; ++i){
                for(int j=0; j<C; ++j){
                    FA[i*C+j] = i*C+j;
                }
            }
        }

        // 查找&路径压缩
        int find(int x){
            if(x == FA[x]) return x;
            return FA[x] = find(FA[x]);
        }

        void uni(int x, int y){
            int fx = find(x);
            int fy = find(y);
            if(fx != fy){
                FA[fx] = fy;
            }
        }

    private:
        unordered_map<int, int> FA;
    };

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        // 并查集求解
        R = m;
        C = n;
        int cnt = 0;// 记录岛屿的数量
        auto island = vector<vector<bool>>(R, vector<bool>(C, false)); // 表示当前坐标是否变成了岛屿
        UnionFind uf = UnionFind(R, C); // 对象建立在栈中, 无需手动调用delete函数
        vector<int> res;
        for(int i=0; i<positions.size(); ++i){
            // 获得变成岛屿的坐标
            int x = positions[i][0];
            int y = positions[i][1];
            // 如果原来是水域则变成陆地进行判定
            if(!island[x][y]){
                cnt++;
                island[x][y] = true;
                // 对当前变为陆地的四个方向进行检测, 如果和其他陆地连城一片(find(x)值相同), 则岛屿数量需要减一
                for(auto d: dirs){
                    int nx = x+d[0];
                    int ny = y+d[1];
                    if(inArea(nx, ny) && island[nx][ny]){
                        int fa = uf.find(x*C+y);
                        int nfa = uf.find(nx*C+ny);
                        if(fa != nfa){ 
                            cnt--;
                            uf.uni(x*C+y, nx*C+ny); 
                        }
                    }
                }
            }
            res.push_back(cnt);
        }
        return res;
    }

private:
    bool inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }

private:
    int R, C;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};
```
```java []
class Solution {

    // 定义并查集
    class UnionFind{
        HashMap<Integer, Integer> FA = new HashMap<>();
        // 初始化并查集
        UnionFind(int R, int C){
            for(int i=0; i<R; ++i){
                for(int j=0; j<C; ++j){
                    FA.put(i*C+j, i*C+j);
                }
            }
        }

        // 查找&路径压缩
        int find(int x){
            // 查找
            int pa = FA.get(x);
            while(pa != FA.get(pa)){
                pa = FA.get(pa);
            }

            // 路径压缩
            int node = -1;
            int fa = x;
            while(fa != FA.get(fa)){
                node = FA.get(fa);
                FA.put(fa, pa);
                fa = node;
            }
            return pa;
        }

        // 合并
        void union(int x, int y){
            int px = find(x);
            int py = find(y);
            if(px != py){
                FA.put(px, py);
            }
        }
    }

    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        R = m;
        C = n;
        List<Integer> res = new LinkedList<Integer>();
        if(positions == null)
            return res;
        
        boolean [][]vis = new boolean[R][C];
        UnionFind uf = new UnionFind(R, C);
        int cnt = 0;

        for(int i=0; i<positions.length; ++i){
            int x = positions[i][0];
            int y = positions[i][1];
            if(!vis[x][y]){
                cnt++;
                vis[x][y] = true;
                for(int []d: dirs){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    if(inArea(nx, ny) && vis[nx][ny]){
                        int fa = uf.find(x*C+y);
                        int nfa = uf.find(nx*C+ny);

                        if(fa != nfa){
                            cnt--;
                            uf.union(x*C+y, nx*C+ny);
                        }
                    }
                }
            }
            res.add(cnt);
        }
        return res;
    }

    private boolean inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }

    private int R, C;
    private int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
}
```
```python []
class Solution:
    # 并查集
    class UnionFind:
        def __init__(self, R, C):
            self.FA = dict()
            for i in range(R):
                for j in range(C):
                    self.FA[i*C+j] = i*C+j 

        # 递归查找&路径压缩
        def find(self, x):
            if x == self.FA[x]:
                return x
            self.FA[x] = self.find(self.FA[x])
            return self.FA[x]

        def union(self, x, y):
            fx = self.find(x)
            fy = self.find(y)
            if fx != fy:
                self.FA[fx] = fy

    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        self.R, self.C = m, n
        island = [[False for _ in range(self.C)] for _ in range(self.R)]
        cnt = 0
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        uf = self.UnionFind(self.R, self.C)
        res = []
        for i in range(len(positions)):
            x = positions[i][0]
            y = positions[i][1]
            if island[x][y] == False:
                cnt += 1
                island[x][y] = True
                for d in dirs:
                    nx, ny = x+d[0], y+d[1]
                    if self.__inArea(nx, ny) and island[nx][ny]==True:
                        if uf.find(x*self.C+y) != uf.find(nx*self.C+ny):
                            cnt-=1
                            uf.union(x*self.C+y, nx*self.C+ny)
            res.append(cnt)

        return res

    def __inArea(self, x, y):
        return 0<=x and x<self.R and 0<=y and y<self.C
```