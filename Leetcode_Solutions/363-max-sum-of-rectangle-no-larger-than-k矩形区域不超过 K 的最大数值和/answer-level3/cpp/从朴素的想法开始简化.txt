
数组有m行n列。且m>>n。

# 1.暴力解法
朴素的想法是遍历所有的行列对,提前算好前缀和(或者矩阵和)。复杂度为$O(m^2n^2)$

# 2.二分搜索
我们把暴力的过程分成两部分：先遍历列边界(或者行边界)，再遍历行边界(或者列边界)。
复杂度为二者的乘积。当我们指定列的左右边界时，计算每行指定列之间的和(使用前缀和做差)。第二步问题变为在一个一维数组里找到一个小于等于k的最大子数组。使用暴力算法时是通过先计算一维数组的前缀和再遍历上下行边界。第二个问题可以进行优化，我们在得到了一部分前缀和后，将其保存到平衡二叉树内，下次使用时可以用二分搜索。将$O(m^2)$简化到$O(mlog(m))$

```c++
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) { // n2m或者m2n，因为n较大所以使用m2n
        vector<vector<int>> row_sum(matrix);
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 1; j < n; j++)
                row_sum[i][j] += row_sum[i][j - 1];
        int res = INT_MIN;
        for(int l = 0; l < n; l++){
            for(int r = l; r < n; r++){
                int pre_sum = 0;
                // 二分搜索
                set<int> prefix;
                prefix.insert(0);
                for(int i = 0; i < m; i++){
                    pre_sum += row_sum[i][r] - row_sum[i][l] + matrix[i][l];
                    auto target = prefix.lower_bound(pre_sum - k);
                    if(target != prefix.end())
                        res = max(res, pre_sum - *target);
                    prefix.insert(pre_sum);
                }
            }
        }
        return res;
    }
};
```