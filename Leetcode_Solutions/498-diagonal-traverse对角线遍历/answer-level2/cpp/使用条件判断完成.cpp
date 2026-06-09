整体代码不难，但是要求不能出错，一次AC确实有难度，我大概试了4 5次自己用例子，就解决了。

就两种走法，向右上角走，或者向左下角走，每个有两种出界的原因，一种是横的下标出界了，一种是纵的下标出界了，

还有两者同时出界（只有m与n相等时会这样），加以判断即可

要注意的是几个内在嵌套else if的顺序，应该优先处理哪种下标出界（当m==n时）。

以示例为例子：

比如说我[0, 0]的坐标 变成[-1, 1]这时候横下标出界了，但是如果我[0, 2]的坐标变成[-1, 3]了，两个下标都出界了，这时候应该往下移动而不是往右，所以else if顺序注意下就好了


不过我看评论有更好的方法，是根据遍历层数的，应该更难想到（但是肯定更好），我这种就是基础方法了，强烈推荐看一下评论的方法


```
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        bool flag = 1;
        int m = matrix.size(), n = matrix[0].size();
        // m行n列
        vector<int> result(m * n);
        for (int i = 0, j = 0, count = 0; count < m * n; ++count) {
            // i为行，j为列
            // cout << i << ", " << j << endl;
            // cout << matrix[i][j] << " ";
            result[count] = matrix[i][j];
            if (flag) {
                // 右上角走，--i，++j
                if (i - 1 >= 0 && j + 1 <= n - 1) {
                    --i;
                    ++j;
                } else if (j + 1 > n - 1) {
                    ++i;
                    flag = 0;
                } else if (i - 1 < 0) {
                    ++j;
                    flag = 0;
                }
            } else {
                if (i + 1 <= m - 1 && j - 1 >= 0) {
                    ++i;
                    --j;
                } else if (i + 1 > m - 1) {
                    ++j;
                    flag = 1;
                } else if (j - 1 < 0) {
                    ++i;
                    flag = 1;
                }
                
            }
        }
        return result;
    }
};
```