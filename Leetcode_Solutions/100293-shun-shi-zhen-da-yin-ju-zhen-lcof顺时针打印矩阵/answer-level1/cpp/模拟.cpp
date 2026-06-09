### 解题思路
简单的模拟题，维护4个边界和2个方向即可，每次遇到边界就将方向顺时针旋转。

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        if(!matrix.size()||!matrix[0].size()) return res;
        int m=matrix.size(),n=matrix[0].size();
        int x=0,y=0,dx=0,dy=1,l=0,r=n-1,low=m-1,up=1;//初始化方向和边界
        for(int i=0;i<m*n;i++){
            res.push_back(matrix[x][y]);
            if(!dx&&dy==1&&y==r){//遇到右边界
                dx=1;
                dy=0;
                r--;
            }else 
            if(dx==1&&!dy&&x==low){//遇到下边界
                dx=0;
                dy=-1;
                low--;
            }else 
            if(!dx&&dy==-1&&y==l){//遇到左边界
                dx=-1;
                dy=0;
                l++;
            }else
            if(dx==-1&&!dy&&x==up){//遇到上边界
                dx=0;
                dy=1;
                up++;
            }
            x+=dx;
            y+=dy;
        }
        return res;
    }
};
```