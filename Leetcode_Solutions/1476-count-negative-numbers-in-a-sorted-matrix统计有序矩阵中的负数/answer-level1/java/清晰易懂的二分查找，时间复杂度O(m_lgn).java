```java
public class Solution {
    public int countNegatives(int[][] grid) {
        int count = 0;
        int m = grid.length;
        int n = grid[0].length;
        //按行来遍历
        for (int i = 0; i < m; i++) {
            int left = 0;
            int right = n - 1;
            while (left <= right) {
                int mid = right - (right - left) / 2;
                if (grid[i][mid] < 0) {
                    if (mid == 0) {
                        count += n;
                        break;
                    }
                    if (grid[i][mid - 1] >= 0) {
                        count += n - mid;
                        break;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    left = mid + 1;
                }
            }
        }
        return count;
    }
}
```