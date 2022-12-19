C++题解，通过方向变量dir以及防止重复的路径矩阵h来进行螺旋路径的遍历。
h[][]是一个二维矩阵代表已经走过的点。
```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int h[1000][1000] = {0},dir=0;//0:right 1:down 2:left 3:up
        vector<int> result;
        if(matrix.empty()) return result;
        int x=0,y=0;
        while(y>=0 && x>=0&&h[x][y] != 1 && x<=(matrix.size()-1) && y<=matrix[0].size() - 1){
            result.push_back(matrix[x][y]);
            h[x][y] = 1;
            if(dir == 0){
                if(y == (matrix[0].size() - 1 )|| h[x][y+1] == 1){
                    dir = 1;
                    x =x+1;
                }
                else{
                    y = y+1;
                }
            }else if(dir == 1){
                if(x == matrix.size()-1 || h[x+1][y] == 1){
                    dir = 2;
                    y = y -1;
                }
                else
                    x = x+1;
            }else if(dir == 2){
                if(y == 0 || h[x][y-1] == 1){
                    dir = 3;
                    x=x-1;
                }
                else
                    y = y-1;
            }else if(dir == 3){
                 if(x == 0 || h[x-1][y] == 1){
                    dir = 0;
                    y = y+1;
                 }
                else
                    x = x - 1;
            }
        }
        return result;
        
    }
};
```
