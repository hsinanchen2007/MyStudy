每次旋转一圈。 

class Solution {
    public void rotate(int[][] matrix) {
        if (matrix.length == 0) {
            return;
        }
        int min = 0;
        int max = matrix.length - 1;
        while (min <= max) {
            for (int i = 0; i + min < max; i++) {
                int tmp = matrix[min][min + i];
                // 0, 0 的位置为最后一个
                matrix[min][min + i] = matrix[max - i][min];
                // 3,0的位置
                matrix[max - i][min] = matrix[max][max - i];
                // 3，3的位置
                matrix[max][max - i] = matrix[min + i][max];
                matrix[i + min][max] = tmp;
            }
            min ++; 
            max --;
        }
    }
}