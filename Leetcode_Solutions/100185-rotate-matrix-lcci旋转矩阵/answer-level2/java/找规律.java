![img_0078.png](https://pic.leetcode-cn.com/ec4a02f99b03d97a23c43d70441d676cb654647f34216194d52ef379834e912e-img_0078.png)
![img_0077.png](https://pic.leetcode-cn.com/c49296e5be2b6fa2ea6ae0c53fd18b509d366bb6ac8e919cd32f737508ef8c39-img_0077.png)
```
public void rotate(int[][] matrix) {
        int[][] tem = new int[matrix.length][matrix[0].length];
        int k = matrix.length + 1;
        int temp;
        for (int i = 0; i < matrix.length; i++) {
            k = k-2;
            for (int j = 0; j < matrix[i].length; j++) {
                tem[j][i + k] = matrix[i][j];
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                matrix[i][j]=tem[i][j];
                System.out.println(matrix[i][j]);
            }
        }
    }
```
