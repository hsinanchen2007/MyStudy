1. 由题意可知共有8种变换形式(0,90,180,270,0-flip,90-flip,180-flip,270-flip)
2. 预处理，将每个独立岛屿的岛屿染成不同的颜色，用来作为该岛屿的唯一标识。为了方便染色，染色的序号从2开始，在原有的grid上直接染色即可。
3. 如果从左上角向右下角遍历整个grid，则相同的图形岛屿的dfs序是相同的，原理很容易想一下就清楚了。在这里我们使用字符串来记录dfs序，每到一个点将该点的x和y坐标添加到字符串尾部。求dfs序需要将初始进入dfs的坐标减去，归一坐标，由于长宽均小于50，避免负数(char是无符号的)统一对64取模。
4. 我们使用一个hashmap来存储 dfs序-岛屿颜色对。
5. 首先处理未变换的grid，每次得到一个岛屿的dfs序字符串后，查询hashmap中是否有该dfs序字符串，如果有，则union已存在hashmap中的岛屿的color和当前color；如果不存在，则插入该 dfs序-岛屿颜色对。
6. 分别处理其他7种变换形式的grid，与第4步不同的是，当遇到hashmap中不存在的dfs序时，不用插入，因为这只是已存在的dfs序在另外一种变换形式的对应的dfs序。遇到已存在的dfs序还是union两个颜色即可。
7. 最后输出并查集中一共有几个集合即可。


```cpp
class Solution {
public:
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int rows = 0;
    int cols = 0;
    unordered_map<string, int> hashmap;
    vector<int> ufs;
    int find(int a){
        int fa = ufs[a];
        if(ufs[fa]!=fa){
            fa = find(fa);
            ufs[a] = fa;
        }
        return fa;
    }
    void Union(int a, int b){
        int fa = find(a);
        int fb = find(b);
        ufs[fa] = fb;
    }
    void colorDfs(vector<vector<int>>& grid, int r, int c, int color){
        grid[r][c] = color;
        int newr,newc;
        for(int d=0; d<4; d++){
            newr = r + dir[d][0];
            newc = c + dir[d][1];
            if(newr>=0&&newr<rows&&newc>=0&&newc<cols&&grid[newr][newc]==1){
                colorDfs(grid, newr, newc, color);
            }
        }
    }
    void colorGrid(vector<vector<int>>& grid){
        int color = 2;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]==1){
                    colorDfs(grid, r, c, color++);
                }
            }
        }
        ufs = vector<int>(color, 0);
        for(int i=2; i<color; i++){
            ufs[i] = i;
        }
    }
    void dfs(vector<vector<int>>& grid, int r, int c, int initr, int initc, string& cur){
        grid[r][c] = 0;
        cur += (char)(((r-initr+64)&63) + 1); // 求dfs序需要将初始的坐标减去，归一坐标，由于长宽均小于50，避免负数统一对64取模
        cur += (char)(((c-initc+64)&63) + 1);
        int newr,newc;
        for(int d=0; d<4; d++){
            newr = r + dir[d][0];
            newc = c + dir[d][1];
            if(newr>=0&&newr<rows&&newc>=0&&newc<cols&&grid[newr][newc]!=0){
                dfs(grid, newr, newc, initr, initc, cur);
            }
        }
    }
    void numDistinctIslands(vector<vector<int>> grid) {
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]!=0){
                    int color = grid[r][c];
                    string cur;
                    dfs(grid, r, c, r, c, cur);
                    auto itor = hashmap.find(cur);
                    if(itor!=hashmap.end()){
                        Union(itor->second, color);
                    }
                }
            }
        }
    }
    int numDistinctIslands2(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        colorGrid(grid);
        vector<vector<int>> gridT(cols, vector<int>(rows));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                gridT[j][rows-i-1] = grid[i][j];
            }
        }
        auto tgrid = grid;
        for(int r=0; r<rows; r++){     // 0
            for(int c=0; c<cols; c++){
                if(tgrid[r][c]!=0){
                    int color = tgrid[r][c];
                    string cur;
                    dfs(tgrid, r, c, r, c, cur);
                    auto itor = hashmap.find(cur);
                    if(itor!=hashmap.end()){
                        Union(itor->second, color);
                    } else {
                        hashmap[cur] = color;
                    }
                }
            }
        }
        for(int i=0; i<rows; i++){
            reverse(grid[i].begin(), grid[i].end()); // 0-flip
        }
        numDistinctIslands(grid);

        for(int i=(rows>>1)-1; i>=0; i--){
            swap(grid[i], grid[rows-1-i]);           // 180
        }
        numDistinctIslands(grid);

        for(int i=0; i<rows; i++){
            reverse(grid[i].begin(), grid[i].end()); // 180-flip
        }
        numDistinctIslands(grid);

        int temp = rows;
        rows = cols;
        cols = temp;

        numDistinctIslands(gridT); // 90

        for(int i=0; i<rows; i++){
            reverse(gridT[i].begin(), gridT[i].end()); // 90-flip
        }
        numDistinctIslands(gridT);

        for(int i=(rows>>1)-1; i>=0; i--){
            swap(gridT[i], gridT[rows-1-i]);           // 270
        }
        numDistinctIslands(gridT);

        for(int i=0; i<rows; i++){
            reverse(gridT[i].begin(), gridT[i].end()); // 270-flip
        }
        numDistinctIslands(gridT);

        unordered_set<int> hashset;
        for(int i=ufs.size()-1; i>=2; i--){
            hashset.insert(ufs[i]);
        }
        return hashset.size();
    }
};
```
