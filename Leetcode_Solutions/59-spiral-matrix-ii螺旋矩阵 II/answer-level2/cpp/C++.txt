### 解题思路
思路来自螺旋矩阵I中的一个大神题解，扫描一行一列去掉该行该列，设置上下左右边界进行判断和扫描复制，思想简单，速度也还可以。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int l=0,r=n-1;
        int u=0,d=n-1;
        int m=1;
        vector<vector<int>> result(n,vector<int>(n));
        while(true)
        {
            for(int i=l;i<=r;i++) //向右
            {
                result[u][i]=m;
                m+=1;
            } 
            if(++u>d) break;
            for(int i=u;i<=d;i++) //向下
            {
                result[i][r]=m;
                m+=1;
            }
            if(--r<l) break;
            for(int i=r;i>=l;i--)//向左
            {
                result[d][i]=m;
                m+=1;
            }
            if(--d<u) break;
            for(int i=d;i>=u;i--)//向上
            {
                result[i][l]=m;
                m+=1;
            }
            if(++l>r) break;
        }
        return result;
    }
};
```