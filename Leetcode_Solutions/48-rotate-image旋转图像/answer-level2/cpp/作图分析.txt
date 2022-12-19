
## 解题思路

将矩阵逆时针旋转90°，我们把矩阵分成左上，右上，右下，左下四部分；

观察左上角的元素，发现坐标迭代的次序为：左上 = 左下，左下 = 右下，右下 = 右上，右上 = 左上，依次迭代，就完成了依次旋转

如何确定下标呢？作图是最直观的方式，如下图

![leetcode-48-01](https://pic.leetcode-cn.com/ff75a99976a4979d3fd27de5079cff74e1c6a140c43cf0008f959a5317d30cd0.png)

注意边界：对于左上角的部分，有两条边，我们进行旋转的时候，只能操作一条边；如果操作两条边，四个部分旋转，会存在数据冲突

## 代码实现

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size() , n = matrix[0].size();
        for (int i = 0; i < (m+1) >> 1; i ++){
            for (int j = 0; j< n >> 1; j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[m-j-1][i];
                matrix[m-j-1][i] = matrix[m-i-1][n-j-1];
                matrix[m-i-1][n-j-1] = matrix[j][n-i -1];
                matrix[j][n-i -1] = t;
            }
        }
    }
};
```


[从零开始学算法](https://muyids.github.io/simple-algorithm/)