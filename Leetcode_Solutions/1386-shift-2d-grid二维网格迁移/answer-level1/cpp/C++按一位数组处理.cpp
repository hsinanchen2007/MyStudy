### 解题思路
按一位数组处理，i*n+j是当前的，i*n+j+k是向后移动k次，然后计算  对应的行坐标r和列坐标c

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        if(m<1)
            return grid;
        int n =grid[0].size();
        int t=0;
        int r=0;
        int c=0;
        vector<vector<int>> res(m,vector<int>(n,0));
        //cout<<m*n<<endl;
        k=k%(m*n);
        //cout<<k<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //cout<<i*n+j<<endl;
                t=(i*n+j+k)%(m*n);
                r=t/n;
                c=t-r*n;
                //cout<<t<<"  "<<r<<"  "<<c<<endl;
                res[r][c]=grid[i][j];
            }
        }
        return res;
    }
};
```