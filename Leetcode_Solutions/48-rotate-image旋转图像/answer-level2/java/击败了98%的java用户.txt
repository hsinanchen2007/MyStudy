## 解析
对于这种旋转类的题目。首先要选准基准点。选好基准点以后会事半功倍。本题我么可以选准左上角和右下角两个基准点。
   第一轮对下列数字进行旋转。定点为[0,0]和[3,3]
   [
   [ 5, 1, 9,11],
   [ 2, &emsp;&emsp; &emsp;&emsp;    10],
   [13,    &emsp;&emsp;&emsp;&emsp;   7],
   [15,14,12,16]
   ]

   第二轮对下列数字进行旋转。定点为[1,1]和[2,2]。
   [
   [3, 6],
   [14,12]
   ]
   怎么旋转？对于5，11，16，15这几个数字。首先用tmp暂存5.然后将15放到5的位置，16放到15的位置，11放到16的位置。最后将tmp放到11的位置。
   根据这种规律即可完成旋转。
## 代码
```java
public void rotate(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return;
        }
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = matrix.length - 1;
        int colEnd = matrix[0].length - 1;

        while (rowStart < rowEnd) {
            help(matrix,rowStart,colStart,rowEnd,colEnd);
            rowStart++;
            colStart++;
            rowEnd--;
            colEnd--;
        }
    }

    private void help(int[][] matrix, int rowStart, int colStart, int rowEnd, int colEnd) {
        int time = rowEnd - rowStart;
        for (int i = 0; i < time; i++) {
            int tmp = matrix[rowStart][colStart + i];
            matrix[rowStart][colStart + i] = matrix[rowEnd - i][colStart];
            matrix[rowEnd - i][colStart] = matrix[rowEnd][colEnd - i];
            matrix[rowEnd][colEnd - i] = matrix[rowStart + i][colEnd];
            matrix[rowStart + i][colEnd] = tmp;

        }
    }
```