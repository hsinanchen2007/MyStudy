找规律吧，主要是每次要转换4次才能旋转过来，转换公式为
$$
col_{new} = row
row_{new} = n - 1 - col
$$
交换的时候，不用额外空间；其实n可以去掉了，只是为了好看罢了。这样就只剩下了索引的空间，
```
//    public void swap(int i,int j)
//    {
//        i ^= j;
//        j = i ^ j;
//        i = i ^ j;
//    }

    public void rotate(int[][] matrix)
    {
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0) return;

        int n = matrix.length;

        for(int i = 0; i < n / 2 ; i++)
        {
            for(int j = 0;j < (n + 1) / 2; j++) // 遍历哪个位置是要进行开头的
            {
                matrix[i][j] ^= matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[i][j] ^ matrix[n - j - 1][i];
                matrix[i][j] = matrix[i][j] ^ matrix[n - j - 1][i];

                matrix[n - j - 1][i] ^= matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[n - j - 1][i] ^ matrix[n - i - 1][n - j - 1];
                matrix[n - j - 1][i] = matrix[n - j - 1][i] ^ matrix[n - i - 1][n - j - 1];

                matrix[n - i - 1][n - j - 1] ^= matrix[j][n - i - 1];
                matrix[j][n - i - 1] = matrix[n - i - 1][n - j - 1] ^ matrix[j][n - i - 1];
                matrix[n - i - 1][n - j - 1] = matrix[n - i - 1][n - j - 1] ^ matrix[j][n - i - 1];
            }
        }
    }
```