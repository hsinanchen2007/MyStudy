执行用时 :16 ms, 在所有 C++ 提交中击败了98.89%的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了100.00%的用户

**（1）第一个循环对矩阵中每一个1建立集合，并对其右边和上边的集合做并操作unionSet()。**
**（2）第二个循环对于矩阵中每一个0的周围四个方向中的1，找出属于不同集合的1，并将这些集合的大小加起来再加一便是填补这个0之后的陆地面积。**

```
class Solution {
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    struct elem{
        int parentx, parenty;
        int size;
    };
    
    elem arr[55][55];
    
    void makeSet(int x, int y){
        arr[x][y].parentx = x;
        arr[x][y].parenty = y;
        arr[x][y].size = 1;
    }
    
    void unionSet(int x1, int y1, int x2, int y2){
        elem p1 = find(x1, y1);
        elem p2 = find(x2, y2);
        if(p1.parentx == p2.parentx && p1.parenty == p2.parenty) return;
        if(p1.size > p2.size){
            arr[p2.parentx][p2.parenty].parentx = p1.parentx;
            arr[p2.parentx][p2.parenty].parenty = p1.parenty;
            arr[p1.parentx][p1.parenty].size += arr[p2.parentx][p2.parenty].size;
        }
        else{
            arr[p1.parentx][p1.parenty].parentx = p2.parentx;
            arr[p1.parentx][p1.parenty].parenty = p2.parenty;
            arr[p2.parentx][p2.parenty].size += arr[p1.parentx][p1.parenty].size;
        }
    }
    
    elem find(int x, int y){
        if(arr[x][y].parentx == x && arr[x][y].parenty == y)
            return arr[x][y];
        else {
            elem tmp = find(arr[x][y].parentx, arr[x][y].parenty);
            arr[x][y].parentx = tmp.parentx;
            arr[x][y].parenty = tmp.parenty;
            return find(arr[x][y].parentx, arr[x][y].parenty);
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0) continue;
                makeSet(i, j);
                if(i-1>=0 && grid[i-1][j] == 1){
                    unionSet(i, j, i-1, j);
                }
                if(j-1>=0 && grid[i][j-1] == 1){
                    unionSet(i, j, i, j-1);
                }
            }
        }
        int ans = -1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    int visited[55][55] = {0}, tans = 1;
                    for(int k = 0; k < 4; k++){
                        int x = i+dir[k][0];
                        int y = j+dir[k][1];
                        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y] == 0) continue;
                        elem p = find(x, y);
                        if(grid[x][y] == 1 && visited[p.parentx][p.parenty] == 0){
                            visited[p.parentx][p.parenty] = 1;
                            tans += p.size;
                        }
                    }
                    ans = max(ans, tans);
                }
            }
        }
        return (ans == -1)? grid.size()*grid[0].size() : ans;
    }
};
```
