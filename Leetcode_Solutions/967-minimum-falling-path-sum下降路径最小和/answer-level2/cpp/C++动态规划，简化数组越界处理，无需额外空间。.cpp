**在矩阵周围添加一圈 inf = 101 作为边界，避免处理数组越界的情况。**
从**倒数第二行**开始向上求解，更新每个元素为其下降后的最小值。
举例：
对于元素 A[i][j]，设置临时元素 temp = A[i][j]
其可下降的三个元素为：left = A[i+1][j-1], mid = A[i+1][j], right = A[i+1][j+1]
更新 A[i][j] = min(left + temp, mid + temp, right + temp)
全部元素更新完毕后，第 1 行元素的最小值即为返回值。
```
class Solution {
public:
    /*
     核心思路：
     动态规划。
     首先在矩阵周围添加一圈 inf = 101 作为边界，避免处理数组越界的情况。
     从倒数第二行开始向上求解，更新每个元素为其下降后的最小值。
     举例：
     对于元素 A[i][j]，设置临时元素 temp = A[i][j]
     可下降的三个元素为：
                     left = A[i+1][j-1],
                      mid = A[i+1][j],
                      right = A[i+1][j+1]
     更新 A[i][j] = min(left + temp, mid + temp, right + temp)
     全部元素更新完毕后，第 1 行元素的最小值即为返回值。
    
     */
    const int inf = 101;
    // 辅助函数，给矩阵添加 inf 边界。
    void buildBoundary(vector<vector<int>>& A, int m, int n) {
        if (m == 0 || n == 0) return;
        vector<int> boundary(n, inf);
        A.insert(A.begin(), boundary);
        A.push_back(boundary);
        for (auto &array : A) {
            array.insert(array.begin(), inf);
            array.push_back(inf);
        }
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        // A 为空情况的处理。
        int m = (int)A.size();
        if (m == 0) return INT_MIN;
        int n = (int)A[0].size();

        // 添加边界
        buildBoundary(A, m, n);


        for (int row = m-1; row > 0; --row) {
            for (int col = 1; col <= n; ++col) {
                // 尽量使用本地变量运算，减少对数组的访问次数，提高运行速度。
                int temp = A[row][col];
                int down = row+1;
                int left, mid, right;
                // 分别计算当前元素 A[row][col] 与下方三个路径值之和。
                left = temp+A[down][col-1];
                mid = temp+A[down][col];
                right = temp+A[down][col+1];
                A[row][col] = min(min(left, mid), min(mid, right));
            }
        }
        int result = INT_MAX;
        for (int i = 1; i <=n; ++i)
            result = result > A[1][i] ? A[1][i] : result;
        return result;
    }
};
```
