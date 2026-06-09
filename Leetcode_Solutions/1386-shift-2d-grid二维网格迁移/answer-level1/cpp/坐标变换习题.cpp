本题涉及到两个坐标变换的问题：
    1. 将二维数组转换成一维数组；
    2. 设结果数组为res，按照题意将一维数组进行变换`grid[index]]--res[index+k]`，其中index的范围是[0,n*m-1],当index+k的值大于右边界时，我们对做区域操作即`(index+k)%(n*m)`保证所有变换后的坐标都在[0，n*m-1]范围内，这样移动k次后的坐标的对应关系公式就可以计算出来了
    3. 对应的二维数组关系为：设grid数组的横坐标为i，纵坐标为j，res对应的横坐标为((i*m+j+k)%(n*m))/m,纵坐标为((i*m+j+k)%(n*m))%m，通过两层for循环即可得到res

```
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        k%=n*m;
        auto res=grid;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int temp=(i*m+j+k)%(n*m);
                res[temp/m][temp%m]=grid[i][j];
            }

        }
        return res;
    }
};
```
