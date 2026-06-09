```
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int cubes = 0, faces = 0, ans = 0;
        int N = grid.size();
        /* 减法 每个cube提供6个表面积，两个接触的cube要减去2倍的接触面积 S=6cubes-2faces*/
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                /*对于每一堆，cube = v; 自接触面积为v-1*/
                if(grid[i][j] > 0) {
                    cubes += grid[i][j];
                    faces += grid[i][j] - 1;
                }
                /*对于[i，j]右侧，接触面为v1,v2中小的那个数值*/
                if(i+1 < N)
                    faces += min(grid[i][j], grid[i+1][j]);
                /*对于[i，j]上侧，接触面为v1,v2中小的那个数值*/
                if(j+1 < N)
                    faces += min(grid[i][j], grid[i][j+1]);
            }
        }
        /* 使用S=6cubes-2faces，不重复计算。只需计算右上/左上/左下/右下，四种方案中的一种，
        计算四个方向也行，表达式会变为S=6cubes-2face1-face2，face1为自接触面积，face2为四方向接触面
        或者表达式变为S=6cubes-face，其中自接触面积变为2(v-1)，四方向接触面全计算*/
        ans = 6 * cubes - 2 * faces;
        return ans;

    }
};
```