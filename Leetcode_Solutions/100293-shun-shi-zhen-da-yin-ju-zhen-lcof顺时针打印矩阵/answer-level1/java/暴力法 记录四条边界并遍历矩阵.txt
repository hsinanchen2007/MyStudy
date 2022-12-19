![image.png](https://pic.leetcode-cn.com/9d42e41e5b9a606c90bb92c620109a54c2b9cd902d6becbdc7fa84c94cc5205b-image.png)

```
class Solution {
    public static int[] spiralOrder(int[][] matrix) {
        int length = matrix.length;
        if (length == 0) {
            return new int[0];
        }
        int width = matrix[0].length;
        int[] res = new int[length * width];
        int count = 0;
        int t = 0;
        int r = width - 1;
        int b = length - 1;
        int l = 0;
        while (count <= length * width - 1) {
            for (int i = l; i <= r; i++) {
                res[count] = matrix[t][i];
                count++;
            }
            t++;
            for (int j = t; j <= b; j++) {
                res[count] = matrix[j][r];
                count++;
            }
            r--;
            if ( count > length * width - 1) {
                break;
            }
            for (int m = r; m >= l; m--) {
                res[count] = matrix[b][m];
                count++;
            }
            b--;
            for (int n = b; n >= t; n--) {
                res[count] = matrix[n][l];
                count++;
            }
            l++;
        }
        return res;
    }
}
```
