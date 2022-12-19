1. 我们定义`[0,1,2,3]`分别代表左右上下四个方向。`L = 0, R = 1, U = 2, D = 3`。
2. 定义数组`dict[i][j] = 1`代表单元格类型`i`是否含有`j`侧方向的开口。
比如单元格类型`1`可以与左右相邻的单元格相通，即该单元格含有左侧和右侧的开口。：
![1](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/03/21/main.png)
则我们定义`dict[1][0] = 1 ,dict[1][1] = 1`,表示街道`1`可以与左侧和右侧的单元格相连。
3. 我们定义connect数组表示当前开口方向与哪个方向的开口相连，比如左侧的单元格可以与右侧的单元格开口相连，上侧的单元格可以与下侧的单元格开口相连。与四个开口方向为`{L,R,U,D}`相连的开口方向为`{R,L,D,U}`。
4. 我们通过并查集，查询当前单元格与上下左右4个方向相邻的单元格是否可以互联，如果互联则进行并集。
```c++
class Solution {
public:
    const int L = 0;
    const int R = 1;
    const int U = 2;
    const int D = 3;

    int find(vector<int> & f, int x){
        while(x != f[x]){
            x = f[x];
        }
        return x;
    }

    bool uni(vector<int> & f,int x,int y){
        int x1 = find(f,x);
        int y1 = find(f,y);
        if(x1 > y1) f[x1] = y1;
        else f[y1] = x1;
        return true;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> f(row*col,0);
        int d[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        int dict[7][4];
        int connect[4] = {R,L,D,U};
        
        /*initial*/
        memset(dict,0,sizeof(dict));
        dict[1][L] = 1;
        dict[1][R] = 1;
        dict[2][U] = 1;
        dict[2][D] = 1; 
        dict[3][L] = 1;
        dict[3][D] = 1;
        dict[4][R] = 1;
        dict[4][D] = 1;
        dict[5][L] = 1;
        dict[5][U] = 1;
        dict[6][R] = 1;
        dict[6][U] = 1;
        for(int i = 0; i < row*col; ++i){
            f[i] = i;
        }
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                for(int k = 0; k < 4; ++k){
                    int x = d[k][0] + i;
                    int y = d[k][1] + j; 
                    if(x < 0 || x >= row || y < 0 || y >= col) continue;
                    if(!dict[grid[i][j]][k]) continue;
                    if(dict[grid[i][j]][k]&&dict[grid[x][y]][connect[k]]){
                        uni(f,i*col+j,x*col+y);
                    }
                }
            }         
        }

        if(find(f,0) == find(f,row*col-1)) return true;
        return false;
    }
};
```