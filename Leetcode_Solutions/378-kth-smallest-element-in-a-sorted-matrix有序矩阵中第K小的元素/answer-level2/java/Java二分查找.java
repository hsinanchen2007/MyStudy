与该题类似的题目：373, 378, 668, 719, 786，本题是这种类型题目的最基础的题目，一定要搞懂，最简单的方法就是二分查找
```
class Solution {
    // 索引搜索 +  范围搜索
    // 二维数组第一个元素是最小值，最后一个元素是最大值，在这两个数之间使用二分法寻找 第K小元素
    // min(matrix) <= candidate <= max(matrix),  然后再次使用二分法统计 每一行比candidate小的元素数目，来判断candidate是否符合要求
    public int kthSmallest(int[][] matrix, int k) {
        int lo = matrix[0][0], hi = matrix[matrix.length-1][matrix.length-1];
        int mid, count;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            count = 0;
            for (int i = 0; i < matrix.length; i++) {
                count += countRow(matrix[i], mid);
            }
            if (count >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
    // 二分法：每一行 <= target 的数目，也就是 下边界
    public int countRow(int[] row, int target) {
        int lo = 0, hi = row.length;
        int mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (row[mid] > target) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
}
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！
