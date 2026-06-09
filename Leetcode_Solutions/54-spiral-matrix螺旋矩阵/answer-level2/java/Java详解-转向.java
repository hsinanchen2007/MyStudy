class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if (matrix.length == 0 || matrix[0].length == 0)
            return result;

        int maxRow = matrix.length;
        int maxCol = matrix[0].length;
        boolean[][] visited = new boolean[maxRow][maxCol];

        int len = maxRow * maxCol;
        int row = 0;
        int col = 0;

        //0 右 1 下 2 左 3 上
        int direction = 0;
        for (int index = 0; index < len; index++) {
            visited[row][col] = true;
            result.add(matrix[row][col]);

            switch (direction) {
                case 0:
                    if (col == maxCol - 1 || visited[row][col + 1]) {
                        direction = 1;
                        row++;
                    } else {
                        col++;
                    }
                    break;
                case 1:
                    if (row == maxRow - 1 || visited[row + 1][col]) {
                        direction = 2;
                        col--;
                    } else {
                        row++;
                    }
                    break;
                case 2:
                    if (col == 0 || visited[row][col - 1]) {
                        direction = 3;
                        row--;
                    } else {
                        col--;
                    }
                    break;
                case 3:
                    if (row == 0 || visited[row - 1][col]) {
                        direction = 0;
                        col++;
                    } else {
                        row--;
                    }
                    break;
            }
        }

        return result;
    }
}