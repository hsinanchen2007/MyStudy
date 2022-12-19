```
    public void rotate(int[][] matrix) {
        for (int i = 0; i < matrix.length/2; i++) {
            int[] line = matrix[i];
            for (int j = i; j < line.length-i-1; j++) {
                int maxIndex = line.length - 1;
                int temp = matrix[i][j];
                matrix[i][j] = matrix[maxIndex - j][i];
                matrix[maxIndex - j][i]=matrix[maxIndex - i][maxIndex - j];
                matrix[maxIndex - i][maxIndex - j]=matrix[j][maxIndex - i];
                matrix[j][maxIndex - i] = temp;
            }
        }
    }
```
