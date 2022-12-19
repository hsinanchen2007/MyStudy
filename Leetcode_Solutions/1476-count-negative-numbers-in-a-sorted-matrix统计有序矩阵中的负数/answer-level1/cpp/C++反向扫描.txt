从下网上扫描每一行，那么每行的“第一个负数”出现的位置`pos`是递增的。

一旦一行里没有找到负数，再往上面的行找也不可能有了，直接`break`掉。

```c++
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m)
            return 0;
        int n = grid[0].size();
        if(!n)
            return 0;
        int ans = 0;
        int pos = 0 ;
        for(int i=m-1;i>=0;i--) {
            for(int j=pos;j<n;j++) {
                if(grid[i][j]<0) {
                    pos = j;
                    ans += n-pos;
                    goto NEXTROW;
                }
            }
            break;
            NEXTROW:
            ;
        }
        return ans;
    }
};
```