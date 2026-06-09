```
class Solution {
    public static int[][] updateMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] != 0) {
                    ArrayList<Integer> list = new ArrayList<>();
                    calcute(list, matrix, i, j, 0, "");
                    matrix[i][j] = Collections.min(list);
                }
            }
        }
        return matrix;
    }
    public static void calcute(ArrayList<Integer> list, int[][] matrix, int row, int col, int sum, String pass) {

        if (row > 0 && !pass.equals("down")) {
            int Sum = sum;
            if (matrix[row - 1][col] == 0) {
                Sum += 1;
                list.add(Sum);
                return;
            } else {
                if (list.size() > 0 && Sum >= Collections.min(list)) {
                    return;
                }
                Sum += 1;
                calcute(list, matrix, row - 1, col, Sum, "top");
            }
        }
        if (row < matrix.length - 1 && !pass.equals("top")) {
            int Sum = sum;
            if (matrix[row + 1][col] == 0) {
                Sum += 1;
                list.add(Sum);
                return;
            } else {
                if (list.size() > 0 && Sum >= Collections.min(list)) {
                    return;
                }
                Sum += 1;
                calcute(list, matrix, row + 1, col, Sum, "down");
            }
        }
        if (col < matrix[0].length - 1 && !pass.equals("left")) {
            int Sum = sum;
            if (matrix[row][col + 1] == 0) {
                Sum += 1;
                list.add(Sum);
                return;
            } else {
                if (list.size() > 0 && Sum >= Collections.min(list)) {
                    return;
                }
                Sum += 1;
                calcute(list, matrix, row, col + 1, Sum, "right");
            }
        }
        if (col > 0 && !pass.equals("right")) {
            int Sum = sum;
            if (matrix[row][col - 1] == 0) {
                Sum += 1;
                list.add(Sum);
                return;
            } else {
                if (list.size() > 0 && Sum >= Collections.min(list)) {
                    return;
                }
                Sum += 1;
                calcute(list, matrix, row, col - 1, Sum, "left");
            }
        }
    }
}
```
