每个块的表面积为 6, 设总块数为n，那么总面积为 sum = 6*n。
设最终答案为 anw， 初始时 anw = sum。然后枚举相邻的情况，每有两块相邻，anw 就会减 2 。
相邻可以分两种情况讨论：
**第一种：顶面和底面相邻的，即堆在一起的**。
设每堆的块数为$H_i$，那么有$anw -= \sum max(0, H_i-1)*2$

**第二种：前面和后面 或者 左面和右面相邻的**。这种可以按堆相邻计算。
枚举堆的，设当前堆的高度为$H_x$，与其某个面相邻的堆的高度为$H_y$
，那么有$anw -= min(H_x, H_y)$。

详见代码：

```
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum = 0;
        
        int dx[] = { 0,  0, -1,  1};
        int dy[] = {-1,  1,  0,  0};

        for(int i = 0, n = grid.size(); i < n; ++i) {
            for(int k = 0, m = grid[i].size(); k < m; ++k) {
                if(grid[i][k] <= 0 ) {
                    continue;
                }
                sum += grid[i][k]*4 + 2;
                for(int j = 0; j < 4; j++) {
                    int tx = i + dx[j], ty = k+dy[j];
                    if(0 <= tx && tx < n && 0 <= ty && ty < m) {
                        sum -= min(grid[i][k], grid[tx][ty]);
                    }
                }
            }
        }
        return sum;
    }
};
```
![微信图片_20200324170704.gif](https://pic.leetcode-cn.com/f2809f1afbb8396bfe05598c0d0b67fd83f38db03d41761ef1217f2c4db1571f-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200324170704.gif)

# 扫码关注 知识加倍
![qrcode_for_gh_6e5f8557b1f8_258.jpg](https://pic.leetcode-cn.com/f342732b3946279400738d041c621f9e1433a5b4bc428a2aee6df54d091f2c4-qrcode_for_gh_6e5f8557b1f8_258.jpg)
