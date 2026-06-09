```
class Solution {
        public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return new int[0];
        }
        
        int m = matrix.length;
        int n = matrix[0].length;
        int[] res = new int[m * n];
        
        int r = 0;
        int c = 0;
        
        int index = 0;
        boolean down = false;
        while(index < m * n) {
            res[index++] = matrix[r][c];
            if (!down) { // 向斜上方遍历
                if (c == n - 1) {
                    r++;
                    down = true;
                } else if (r == 0) {
                    c++;
                    down = true;
                } else {
                    r--;
                    c++;
                }
                continue;
            }
            
            if (down) { // 向斜下方遍历
                if (r == m - 1) {
                    c++;
                    down = false;
                } else if (c == 0) {
                    r++;
                    down = false;
                } else {
                    r++;
                    c--;
                }
                continue;
            }
        }
        
        return res;
    }
}
```