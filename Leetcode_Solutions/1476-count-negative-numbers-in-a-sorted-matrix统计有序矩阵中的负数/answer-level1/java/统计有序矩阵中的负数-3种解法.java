>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(mn)，其中m是矩阵grid的行数，n是矩阵grid的列数。空间复杂度是O(1)。

执行用时：1ms，击败64.54%。消耗内存：41.8MB，击败100.00%。

```java
public class Solution {
    public int countNegatives(int[][] grid) {
        int m;
        if (null == grid || (m = grid.length) == 0) {
            return 0;
        }
        int n;
        if (null == grid[0] || (n = grid[0].length) == 0) {
            return 0;
        }
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0 && grid[i][j] < 0 ; j--) {
                result++;
            }
        }
        return result;
    }
}
```

# 解法二：反向ceil()函数的实现

时间复杂度是O(mlogn)，其中m是矩阵grid的行数，n是矩阵grid的列数。空间复杂度是O(1)。

执行用时：0ms，击败100.00%。消耗内存：41.9MB，击败100.00%。

```java
public class Solution {
    public int countNegatives(int[][] grid) {
        int m;
        if (null == grid || (m = grid.length) == 0) {
            return 0;
        }
        int n;
        if (null == grid[0] || (n = grid[0].length) == 0) {
            return 0;
        }
        int result = 0;
        for (int i = 0; i < m; i++) {
            int indexOf0 = ceil(grid[i], 0);
            if (indexOf0 < n) {
                result += n - indexOf0;
                if (grid[i][indexOf0] == 0) {
                    result--;
                }
            }
        }
        return result;
    }

    private int ceil(int[] nums, int target) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) {  //如果是非递减排列的nums数组，此处是nums[mid] <= target
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left - 1 >= 0 && nums[left - 1] == target) {
            return left - 1;
        }
        return left;
    }
}
```

# 解法三：从矩阵左下角开始遍历

时间复杂度是O(m + n)，其中m是矩阵grid的行数，n是矩阵grid的列数。空间复杂度是O(1)。

执行用时：0ms，击败100.00%。消耗内存：41.7MB，击败100.00%。

```java
public class Solution {
    public int countNegatives(int[][] grid) {
        int m;
        if (null == grid || (m = grid.length) == 0) {
            return 0;
        }
        int n;
        if (null == grid[0] || (n = grid[0].length) == 0) {
            return 0;
        }
        int result = 0, i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            while (j < n && grid[i][j] >= 0) {
                j++;
            }
            result += n - j;
            i--;
        }
        return result;
    }
}
```