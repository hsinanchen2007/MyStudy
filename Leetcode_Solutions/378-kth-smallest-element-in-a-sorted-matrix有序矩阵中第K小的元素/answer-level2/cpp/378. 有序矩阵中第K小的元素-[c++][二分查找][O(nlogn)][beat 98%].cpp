索引搜索+范围搜索

``` cpp
class Solution {
public:
    // O(nlogn)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int lo = matrix[0][0], hi = matrix.back().back();
        // O(log(max_val - min_val)) = O(1)，32 位整型最多 32 次
        while (lo < hi) {
            int mid = lo + (hi - lo >> 1);
            int count = 0;
            // O(n)
            for (int i = 0; i < matrix.size(); ++i) {
                // O(logn)
                count += search(matrix[i], mid); // <= mid 的元素个数
            }
            if (k <= count) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    
    // 标准 upperbound 模板。查找第一个 > target 的元素的位置。
    // 也就是 <= target 的元素的个数。
    int search(vector<int>& row, int target) {
        int lo = 0, hi = row.size();
        while (lo < hi) {
            int mid = lo + (hi - lo >> 1);
            if (row[mid] > target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
```
