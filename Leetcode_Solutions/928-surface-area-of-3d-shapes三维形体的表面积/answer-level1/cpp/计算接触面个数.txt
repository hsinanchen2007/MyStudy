```C++
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid);
};

// 计算立体结构的表面积，因为内部一些暴露的表面可能会被某侧的视图挡住
// 这部分面积在计算各个侧面视图时可能并没有计算计入，因此计算方法不准确
// 而应该计算的时接触面的个数，每当存在一个接触面，则导致面积-2
// 计算接触面从xyz轴三个方向考虑（考虑z轴上每层都可能存在接触面积）
int Solution::surfaceArea(vector<vector<int>>& grid) {
    if(grid.empty()) return 0;
    // 扫描x方向上的接触面个数时候可以同时计算每层z方向上的接触面个数
    int contactx = 0, contacty = 0, contactz = 0;
    int n = grid.size(), total = 0;
    for (int i =  0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) { total += grid[i][j]; contactz += grid[i][j] - 1; }
            if ((j-1) >= 0) contactx += min(grid[i][j], grid[i][j-1]);
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if ((i-1) >= 0) contacty += min(grid[i][j], grid[i-1][j]);
        }
    }
    return total * 6 - (contactx + contacty + contactz) * 2;
}
```
