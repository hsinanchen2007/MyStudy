### 解题思路
思路比较简单，由于都是方阵，比螺旋矩阵Ⅰ少了个判断
再有就是多用`++`，速度比较快
![image.png](https://pic.leetcode-cn.com/776e97558cedb1a9ce2237c21a06d7d1cb155ad454188bc2ea3f68004089f88d-image.png)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> r(n,0);
        vector<vector<int>> matrix(n,r);
        int x=0,y=-1;
        int high=0,low=0,left=0,right=0;
        int num=1;
        int tmpx,tmpy;
        while(true)
        {
            tmpx=x;
            tmpy=y;
            while(++y<n-right)
            {
                matrix[x][y]=num++;
            }
            high++;
            y--;
            while(++x<n-low)
            {
                matrix[x][y]=num++;
            }
            right++;
            x--;
            while(--y>=0+left)
            {
                matrix[x][y]=num++;
            }
            low++;
            y++;
            while(--x>=0+high)    
            {
                matrix[x][y]=num++;
            }
            left++;
            x++;
            if(x==tmpx && y==tmpy)
                break;
        }
        return matrix;
    }
};
```