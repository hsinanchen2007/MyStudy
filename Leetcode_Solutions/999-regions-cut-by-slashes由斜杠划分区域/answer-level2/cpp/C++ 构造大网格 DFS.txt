构造边长为小网格(char a=grid[i][j]) 边长三倍+2的大网格，外围为一圈保护，以简化边界处理
经测试：
执行用时 :8 ms, 在所有 cpp 提交中击败了97.48% 的用户
内存消耗 :11.3 MB, 在所有 cpp 提交中击败了43.75%的用户
'/'对应：
001
010
100

'\\'对应：
100
010
001

' '对应：
000
000（或010）
000

举例：
[
  "\\/",
  "/ "
]
对应的大网格为:
```
11111111
11000011
10100101
10011001
10010001
10100101
11000001
11111111
```
代码如下，欢迎交流和建议：
```
class bigGrid{
public:
    int length;                                 //大网格的边长
    vector<vector<int>> Grid;                   //大网格
    bigGrid(int a){
        length=3*a+2;                                           //每个小格对应一个大格，外围留一圈围墙以简化边界处理
        Grid=vector<vector<int>>(3*a+2,vector<int>(3*a+2,1));   //初始化全部为不可经过
    }
    void FillAll(int a,const vector<string>&grid){              //逐个数据，grid太大，应使用常引用
        for(int i=0;i<a;++i){
            for(int j=0;j<a;++j){
                fill(i,j,grid[i][j]);
            }
        }
    }
    void fill(int x,int y,char choice){         //根据小网格坐标处理大网格
        for(int i=3*x+1;i<3*x+4;++i){
            for(int j=3*y+1;j<3*y+4;++j){
                Grid[i][j]=0;                   //挖空九个格子
            }
        }
        Grid[3*x+2][3*y+2]=1;                   //中心都不可经过，空格也可挖掉中心
        switch(choice){
            case '\\':
                Grid[3*x+1][3*y+1]=1;
                Grid[3*x+3][3*y+3]=1;
                break;
            case '/':
                Grid[3*x+1][3*y+3]=1;
                Grid[3*x+3][3*y+1]=1;
                break;
            /*
            case ' ':
                Grid[3*x+2][x*y+2]=0;
                break;
            */
        }
    }
    int DFS(){                                  //DFS，计算连通域数量
        int a=0;
        for(int i=0;i<length;++i){
            for(int j=0;j<length;++j){          //从空心处遍历
                if(!Grid[i][j]){
                    dfs(i,j);
                    ++a;
                }
            }
        }
        return a;
    }
    void dfs(int i,int j){                      //dfs，连通域内
        Grid[i][j]=1;
        if(!Grid[i-1][j]) dfs(i-1,j);           //每个可访问格子只与上下左右四个格子有连接
        if(!Grid[i][j-1]) dfs(i,j-1);           //围墙不可为dfs起点，不会越界
        if(!Grid[i+1][j]) dfs(i+1,j);
        if(!Grid[i][j+1]) dfs(i,j+1);
    }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int len=grid.size();
        bigGrid Ans(len);
        Ans.FillAll(len,grid);
        return Ans.DFS();
    }
};
```
