```
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        int h = matrix.length, w = 0;
        if (h != 0) {
            w = matrix[0].length;
        }
        int[] res = new int[h * w];
        int ind = 0;

        int x = 0, y = 0;

        int count = 0;

        while (ind < h * w) {
            while (y < w - count && ind < h * w) {
                res[ind++] = matrix[x][y++];
            }
            x++;
            y--;
            while (x < h - count && ind < h * w) {
                res[ind++] = matrix[x++][y];
            }
            x--;
            y--;
            while (y >= count && ind < h * w) {
                res[ind++] = matrix[x][y--];
            }
            x--;
            y++;
            while (x > count && ind < h * w) {
                res[ind++] = matrix[x--][y];
            }
            y++;
            x++;
            count++;
        }
        return res;
    }
}
```
