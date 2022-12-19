```
8 1 6   8 3 4   6 1 8   6 7 2
3 5 7   1 5 9   7 5 3   1 5 9
4 9 2   6 7 2   2 9 4   8 3 4
    
4 9 2   4 3 8   2 9 4   2 7 6
3 5 7   9 5 1   7 5 3   9 5 1
8 1 6   2 7 6   6 1 8   4 3 8
```

1. 三阶幻方总共有8种可能，每种可能有9位数字，每位数字最大为9，可以编码在一个 int 中，如第一个可以编码为 816357492。
2. 把幻方右下角即坐标{2, 2}点作为基准，用3x3的框遍历矩阵。
3. 以对幻方相同的编码方式，编码3x3框内的数字。
4. 对满足幻方的3x3框计数。
5. unordered_set 的 count 方法 当 sum 在集合内时返回1，不在时返回0，节省了if判断。

```c++
class Solution {
public:
    int numMagicSquaresInside(const vector<vector<int>>& grid) {
        const unordered_set<int> s{816357492, 834159672, 618753294, 672159834,
                                   492357816, 438951276, 294753618, 276951438};
        const int offset[][2] = {{-2, -2}, {-2, -1}, {-2, 0},
                                 {-1, -2}, {-1, -1}, {-1, 0},
                                 { 0, -2}, { 0, -1}, { 0, 0}};
        int ans = 0;
        for (int i = 2; i < grid.size(); ++i) {
            for (int j = 2; j < grid.size(); ++j) {
                int sum = 0;
                for (int k = 0; k < 9; ++k) {
                    sum *= 10;
                    sum += grid[i + offset[k][0]][j + offset[k][1]];
                }
                ans += s.count(sum);
            }
        }
        return ans;
    }    
};
```
