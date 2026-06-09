
使用快速排序有个问题就是需要知道左右边界，这也是我在做这道题的时候最头疼的一点。左上角的坐标很容易确定，但是右下角的坐标对于我来说有点难确定，想了半天才搞懂。
代码如下：

```
class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int m = mat.length;
        if (m == 0) {
            return mat;
        }
        int n = mat[0].length;

        for (int i = 0; i < n; i++) {
            int up = 0, left = i;
            int right = Math.min(left + m - 1, n - 1);
            int down = right - left;
            specialQuickSort(mat, up, left, down, right);
        }

        for (int i = 0; i < m; i++) {
            int up = i, left = 0;
            int down = Math.min(up + n - 1, m - 1);
            int right = down - up;
            specialQuickSort(mat, up, left, down, right);
        }
        return mat;
    }

    public void specialQuickSort(int[][] a, int up, int left, int down, int right) {
        //(up, left) 是左上角元素的坐标，(down, right) 是右下角元素的坐标
        if (left > right) {
            return;
        }
        int t = a[up][left];
        int x1 = up, i = left, x2 = down, j = right;
        while (i != j) {
            while (a[x2][j] >= t && j > i) {
                x2--;
                j--;
            }
            while (a[x1][i] <= t && j > i) {
                x1++;
                i++;
            }
            if (i < j) {
                swap(a, x1, i, x2, j);
            }
        }
        swap(a, up, left, x1, i);
        specialQuickSort(a, up, left, x1 - 1, i - 1);
        specialQuickSort(a, x1 + 1, i + 1, down, right);
    }

    public void swap(int[][] a, int up, int left, int down, int right) {
        int t = a[up][left];
        a[up][left] = a[down][right];
        a[down][right] = t;
        return;
    }
}
```
