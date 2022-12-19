```
public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        int m = matrix.length, n = 0;
        if (m > 0) {
            n = matrix[0].length;
        }
        int ceng = 0, i = 0, j = 0, size = m * n;
        while (res.size() < size) {
            for (; res.size() < size && j < n - ceng; j++) {
                res.add(matrix[i][j]);
            }
            ++i;
            --j;
            for (; res.size() < size && i < m - ceng; i++) {
                res.add(matrix[i][j]);
            }
            --j;
            --i;
            for (; res.size() < size && j >= ceng; j--) {
                res.add(matrix[i][j]);
            }
            ++j;
            --i;
            for (; res.size() < size && i > ceng; i--) {
                res.add(matrix[i][j]);
            }
            ++i;
            ++j;
            ceng++;
        }
        return res;
    }
```
