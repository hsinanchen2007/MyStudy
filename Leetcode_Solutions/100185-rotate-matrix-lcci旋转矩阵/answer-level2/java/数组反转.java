```
public static void rotate(int[][] matrix) {

        int maxArrLen = matrix.length - 1;
        int cycNums = matrix.length / 2;
        for (int n = 0; n < cycNums; n++) {

            for (int i = 0; i < maxArrLen - n * 2; i++) {
                int temp1 = 0; 
                temp1 = matrix[n][n + i]; 

                matrix[n][n + i] = matrix[maxArrLen - n - i][n];
                matrix[maxArrLen - n - i][n] = matrix[maxArrLen - n][maxArrLen - n - i];
                matrix[maxArrLen - n][maxArrLen - n - i] = matrix[n + i][maxArrLen - n];
                matrix[n + i][maxArrLen - n] = temp1;
            }

        }

    }
```

说白了，就是一圈我进行赋值，外圈好了，我处理内圈。一圈一圈往里面走
1234
4557
5234
5682

1234
4  7
5  4
5682

上面我反转好了
我处理下面这个圈

55
23
剥洋葱一样，层层往里面剥
