### 解题思路
对矩阵进行顺时针访问时，利用一个标志矩阵判断是否访问过该元素。如果发生越界或者碰到已访问节点则会退一格，并换个方向继续访问。

### 代码

```cpp
class Solution {
    // 表示方向:→、↓、←、↑
    vector<int> di = {0,1,0,-1}; 
    vector<int> dj = {1,0,-1,0};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //空值情况处理
        if(!matrix.size()) return {};
        if(!matrix[0].size()) return matrix[0];

        vector<int> Res;
        int row = matrix.size(),col = matrix[0].size();
        int num = row*col;      //矩阵元素个数
        int x = 0, y=0 ;        //待访问元素坐标
        vector<vector<int>> flag(row,vector<int>(col,1)); //是否访问过该数组
        int k = 0;              //遍历方向        
        while(Res.size()< num){
            if( 0<= x && x<row && 0<= y && y<col && flag[x][y]){
                Res.push_back(matrix[x][y]);
                flag[x][y]=0;
            }
            else{               //越界则回溯一个值，然后换个方向继续走
                x-=di[k]; y-=dj[k];
                k=(++k)%4;
            }
            x+=di[k]; y+=dj[k];
        }
        return Res;
    };
};
```