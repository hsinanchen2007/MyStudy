1. 还是采用倒序的思想，倒是采用了并查集来快速的进行块搜索和合并；
2. 明显运行速度和占用的内存快一些了；
```
class UF{
public:
    UF(int size){
        f = vector<int>(size,0);
        sz = vector<int>(size,1);
        for(int i = 0;i < size; ++i){
            f[i] = i;
        }
    }
    
    int find(int x){
        while(x!=f[x]){
            x = f[x];
        }
        return x;
    }

    bool uni(int x,int y){
        int x1 = find(x);
        int y1 = find(y);
        if(x1 == y1){
            return true;
        }
        
        if(sz[x1] > sz[y1]){
            f[y1] = x1;
            sz[x1] += sz[y1];
        }else{
            f[x1] = y1;
            sz[y1] += sz[x1];
        }
        return true;
    }

    int rank(int x){
        return sz[find(x)];
    }
private:
    vector<int> f;
    vector<int> sz;
};


class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int r = grid.size();
        int c = grid[0].size();
        int n = hits.size();
        vector<int> ans(n,0);
        int d[4][2] = {{},{},{},{}};
        UF uf(r*c+1);
        
        for(vector<int> hit: hits){
            if(grid[hit[0]][hit[1]] == 1){
                grid[hit[0]][hit[1]] = -1;
            }
        }
        
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                int idx = i*c + j;
                if(grid[i][j] == 1){
                    if(i == 0 && grid[i][j] == 1){
                        uf.uni(idx,r*c);
                    }
                    if(i > 0 && grid[i-1][j] == 1){
                        uf.uni(idx,(i-1)*c+j);
                    }
                    if(j > 0 && grid[i][j-1] == 1){
                        uf.uni(idx,i*c+(j-1));
                    }
                }
            }
        }
        
        for(int i = n-1; i >= 0; --i){
            int x = hits[i][0];
            int y = hits[i][1];
            if(grid[x][y] == -1){
                int prev = uf.rank(r*c);
                grid[x][y] = 1;
                if(x > 0 && grid[x-1][y] == 1){
                    uf.uni((x-1)*c+y,x*c+y);
                }
                if(x < r-1 && grid[x+1][y] == 1){
                    uf.uni((x+1)*c+y,x*c+y);
                }
                if(y > 0 && grid[x][y-1] == 1){
                    uf.uni(x*c+y-1,x*c+y);
                }
                if(y < c-1 && grid[x][y+1] == 1){
                    uf.uni(x*c+y+1,x*c+y);
                }
                if(x == 0){
                    uf.uni(x*c+y,r*c);
                }
                int after = uf.rank(r*c);
                int currIndex = uf.find(x*c+y);
                int rootIndex = uf.find(r*c);
                if(currIndex == rootIndex){
                    ans[i] = after - prev - 1;
                }
            }
        }
        
        return ans;
    }
};
```