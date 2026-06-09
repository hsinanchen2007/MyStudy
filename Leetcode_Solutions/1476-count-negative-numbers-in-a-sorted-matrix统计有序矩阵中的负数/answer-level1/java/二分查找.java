```
class Solution {
    public int countNegatives(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }

        int ans = 0;
        for (int[] row : grid) {
            int i = binarySearch(row);
            ans += row.length - i;
        }
        return ans;
    }

    private int binarySearch(int[] row) {
        int l = 0, r = row.length - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (row[mid] >= 0) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}
```
