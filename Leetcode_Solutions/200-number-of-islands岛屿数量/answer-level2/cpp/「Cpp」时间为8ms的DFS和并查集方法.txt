### 解题思路1

基本记录就是，看到一个1，就把它上下左右的1，都变成0，接着把它上下左右的1也变成0，直到1的附近的1都变成0.

也就是

```cpp
11000
11000
00100
00011
```

最终会变成

```cpp
10000
00000
00100
00010
```

一个技巧，dx, dy用于处理当前位置的上下左右移动。-1,0 对应这左移，1,0为右移，0,-1上移，0,1下移。

```cpp
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0, -1, 1};
```

### 代码

```cpp
class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0, -1, 1};
    int numIslands(vector<vector<char>>& grid) {

        int islands = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if( grid[i][j] == '1'){
                    DFS(grid, i, j);
                    islands++;
                }
                
            }
        }
        return islands;
    }

    void DFS(vector<vector<char>>& grid, int row, int col){
        if (grid[row][col] == '0') return;

        grid[row][col] = '0';

        for (int k = 0; k < 4 ;k++){
            int x = row + dx[k];
            int y = col + dy[k];
            if ( x >=0 && x < grid.size() && y >= 0 && y < grid[0].size()){
                if ( grid[x][y] == '0') continue;
                DFS(grid, x, y);
            }
        }
        return ;
    }
};
```

![image.png](https://pic.leetcode-cn.com/39d249c838d2f74ae9b43d8504f2e2b4ed016c5c269d92e1e363bf616233fefe-image.png)


### 结题思路2

这部分主要用到并查集这种数据结构，并查集虽然是算法导论的高级技术和分析技术，但数据结构实现不难，分为三个函数

- 初始化: makeSet
- 合**并**两个集合: unionSet
- **查**找一个集合的代表: parent

实现如下

```cpp
struct DSU{
    vector<int> data;

    void makeSet(int n){
        data.resize(n);
        for (int i = 0; i < n; i++) data[i] = i;
    };

    bool unionSet(int i, int j){
        int p1 = parent(i);
        int p2 = parent(j);
        if ( p1 != p2 ){
            data[p1] = p2;
        } 
        return p1 != p2;

    };

    int parent(int i){
        int root = i;
        while ( data[root] != root){
            root = data[root];
        }
        return root;

    };
};

```

相对于之前DFS，不断的向下递归，并查集首先让所有元素都形成一个圈子，然后检查当前元素和之前元素的关系，如果都是1，那就合并。

```cpp
//当前是1，上边元素是1
               if ( i > 0 && grid[i][j] == '1' && grid[i-1][j] == '1'){
                    ans -= dsu.unionSet(i*n +j, (i-1)*n+j);
                }
//当前1，左边元素是1
                if ( j > 0 && grid[i][j] == '1' && grid[i][j-1] == '1'){
                    ans -= dsu.unionSet(i*n +j, i*n+j-1);
                }
```

### 代码


```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 ) return  0;

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1') ans++;
            }
        }
        DSU dsu;
        dsu.makeSet( m * n);
        for (int i = 0 ; i < m ; i++){
            for ( int j = 0; j < n ; j++){
                if ( i > 0 && grid[i][j] == '1' && grid[i-1][j] == '1'){
                    ans -= dsu.unionSet(i*n +j, (i-1)*n+j);
                }
                if ( j > 0 && grid[i][j] == '1' && grid[i][j-1] == '1'){
                    ans -= dsu.unionSet(i*n +j, i*n+j-1);
                }

            }
        }
        return ans;

    }
};
```