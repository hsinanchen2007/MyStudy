### 解题思路
1. 用一个int变量`direction`代表对角线遍历方向，`direction=1`代表向矩阵右上方移，`direction=-1`代表向左下方移。
2. 代码操作时只需要让行标`i-=direction`、列标`j+=direction`即可实现移动，按方向循环遍历知道超出矩阵边界。
3. 超出边界后`direction*=-1`实现变向，再对行标、列标做简单的操作回到边界位置继续遍历。
    - 右上移动溢出后，行下移一位；如果列同时溢出，再向左下移一位。
    - 坐下移动溢出后，列右移一位；如果行同时溢出，再向右上移一位。

### 代码

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(!m) return res;
        int n=matrix[0].size();
        int direction = 1;
        for(int i=0,j=0;i<m&&j<n;){
            for(;i<m&&j<n&&i>=0&&j>=0;){
                res.push_back(matrix[i][j]);
                i -= direction;
                j += direction;
            }
            if(direction==1){
                i += 1;
                if(j>=n) {i+=1;j-=1;}
            }
            if(direction==-1){
                j+=1;
                if(i>=m) {j+=1;i-=1;}
            }
            direction *= -1;
        }
        return res;
    }
};
```