```
// 100% 0ms(中文) 100% 0ms(英文)
    public List<Integer> spiralOrder(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return new ArrayList<>();
        List<Integer> res = new ArrayList<>();
        boolean[][] flag = new boolean[matrix.length][matrix[0].length];
        int totalCount = matrix.length * matrix[0].length, i = 0, j = 0;
        while (res.size() < totalCount) {
            // 右
            while (j < matrix[0].length && !flag[i][j]) {
                res.add(matrix[i][j]);
                flag[i][j] = true;
                ++j;
            }
            --j;
            ++i;
            // 下
            while (i < matrix.length && !flag[i][j]) {
                res.add(matrix[i][j]);
                flag[i][j] = true;
                ++i;
            }
            --i;
            --j;
            // 左
            while (j >= 0 && !flag[i][j]) {
                res.add(matrix[i][j]);
                flag[i][j] = true;
                --j;
            }
            --i;
            ++j;
            // 上
            while (i >= 0 && !flag[i][j]) {
                res.add(matrix[i][j]);
                flag[i][j] = true;
                --i;
            }
            ++i;
            ++j;
        }
        return res;
    }
```
