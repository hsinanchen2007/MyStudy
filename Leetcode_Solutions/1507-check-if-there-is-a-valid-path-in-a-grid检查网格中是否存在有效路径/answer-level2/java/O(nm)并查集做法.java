将每个网格理解成顶点，每个顶点需要考虑与下方和右边的顶点是否能连通即可。

首先维护四个布尔数组，left，right，up，bot。left[i]表示数字i代表的网格中的路径是否又一个端点在左边，其余的类似。

之后跑一个循环即可，把并查集合并。

最后判断一下(1,1)和(n,m)是否在一个连通块中。

```java
    int n;
    int m;
    public boolean hasValidPath(int[][] grid) {
        boolean[] up = new boolean[7];
        boolean[] bot = new boolean[7];
        boolean[] left = new boolean[7];
        boolean[] right = new boolean[7];
        left[1] = right[1] = true;
        bot[2] = up[2] = true;
        left[3] = bot[3] = true;
        bot[4] = right[4] = true;
        left[5] = up[5] = true;
        right[6] = up[6] = true;
        
        n = grid.length;
        m = grid[0].length;
        
        DSU dsu = new DSU(n * m);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j + 1 < m && right[grid[i][j]] && left[grid[i][j + 1]]){
                    dsu.merge(id(i, j), id(i, j + 1));
                }
                if(i + 1 < n && bot[grid[i][j]] && up[grid[i + 1][j]]){
                    dsu.merge(id(i, j), id(i + 1, j));
                }
            }
        }
        
        return dsu.find(id(0, 0)) == dsu.find(id(n - 1, m - 1));
    }
    
    int id(int i, int j){
        return i * m + j;
    }
```
