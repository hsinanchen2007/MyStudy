![001.PNG](https://pic.leetcode-cn.com/66fc69942afa8bfce1c50326c11765b0bc27495a57e38c74a80caf7f1ffb522b-001.PNG)
```
public static void setZeroes(int[][] matrix) {

    int[][] copy = new int[matrix.length][matrix[0].length];
    for (int i = 0; i < matrix.length; i++) {
        for (int j = 0; j < matrix[0].length; j++) {
            copy[i][j] = matrix[i][j];
        }
    }
    int rows = matrix.length;
    int cols = matrix[0].length;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (copy[i][j]==0){
                becomeZero(matrix,i,j);
            }
        }

    }
}

public static void becomeZero(int[][] nums, int row, int col)
{
    for (int i = 0; i < nums.length; i++) {
        nums[row][i] = 0;
    }
    for (int i = 0; i < nums[0].length; i++) {
        nums[i][col]=0;
    }
}
```
