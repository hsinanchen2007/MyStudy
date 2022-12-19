这一题其实挺好理解的，但是我写复杂了，主要是一些边界的情况没有考虑清楚，遇到以下的坑：
    1. preArray = tmpArray，我的想法是2个数组存放不同的内容，然而我忘记了这样子的话并不是内容的复制，而是让2个指针指向同一个数组，因此tmpArray改变导致preArray（本来不应该改变），使得问题一直排查不出来。
    2. 边界情况没有考虑清楚，更换了之后交界的点的值无法存放原本的应该放入pre的内容，因此需要特殊处理，从临时数组去取原本的值。
    3. 由于我是使用4个index来处理，因此比如倒序取要使用的len，是原本数组的长度，不需要理会colleft和colright的改变。

思路过程：
    1.考虑到是规则的n*n矩阵，就一圈一圈的进行旋转，然后往内层递进即可。
    2、按照顺序将上面行移动到右边列，右边列移动到下面行，下面行移动到左边列，左边列移动到上面行。由于是一个循环，我们需要一个数组来存放某一行或者列的值，使得该行或者列被更新后，可以使用其原本的值来更新下一列或者行。更新和存放同时进行，为了方便，我们使用2个数组来存放，pree存放用于更新当前行列的数据，一个用于存放当前行列本来的数据。
    3、处理一些边界情况，由于到下一轮的时候，当前行列本来的数据会被改变的（如下面行的最右边，已经被右边列更新的，所以这时候获取下面行是获取不到原本的数据的），因此要从pre去获取，因为pre存放的是右边列原本的值，也就存在着下面行最右边交点原本的值。

根据以上思路完成代码，代码比较啰嗦，并不是最好的方法，了解思路即可。
```
 public static void rotate(int[][] matrix) {
        if (matrix == null || matrix.length <= 1) {
            return;
        }

        //n*n，此数组用于存放临时数组
        int[] tmpArray = new int[matrix.length];
        int[] preArray = new int[matrix.length];
        int colLeft = 0, rowUp = 0, colRight = matrix.length - 1, rowDown = matrix.length - 1;

        int len = colRight - colLeft + 1;//目前的宽度
        while ((colRight - colLeft) > 0 && (rowDown - rowUp) > 0) {
            //保存上面行
            for (int col = colLeft; col <= colRight; col++) {
                preArray[col] = matrix[rowUp][col];
            }

            //更新临时数组tmpArray为右边列,用临时数组preArray（上面行）的内容去替换右边列，
            for (int row = rowUp; row <= rowDown; row++) {
                tmpArray[row] = matrix[row][colRight];
                matrix[row][colRight] = preArray[row];
            }
            preArray = tmpArray.clone();

            //更新临时数组tmpArray为下面行,用临时数组preArray（右边列）的内容去替换下面行
            for (int col = colRight; col >= colLeft; col--) {
                if (col == colRight) {
                    tmpArray[len - col - 1] = preArray[col];
                } else {
                    tmpArray[len - col - 1] = matrix[rowDown][col];
                }
                matrix[rowDown][col] = preArray[len - col - 1];
            }
            preArray = tmpArray.clone();


            //更新临时数组tmpArray为左边列,用临时数组preArray（下面行）的内容去替换左边列
            for (int row = rowDown; row >= rowUp; row--) {
                if (row == rowDown) {
                    tmpArray[row] = preArray[row];
                } else {
                    tmpArray[row] = matrix[row][colLeft];
                }

                matrix[row][colLeft] = preArray[len - row - 1];
            }
            preArray = tmpArray.clone();

            //更新临时数组tmpArray为左边列,用临时数组preArray（下面行）的内容去替换左边列
            for (int col = colLeft; col <= colRight; col++) {
                matrix[rowUp][col] = preArray[len - col - 1];
            }

            //此时完成n*n二维矩阵最外层，接下来往内压缩一层
            colLeft++;
            colRight--;
            rowUp++;
            rowDown--;
        }
    }
```

题解这个方法更为精妙
转置矩阵后，逐行对称
```
  public static void rotate(int[][] matrix) {
        if (matrix == null || matrix.length <= 1) {
            return;
        }
        int n = matrix.length;

        //先转置矩阵
        for (int i = 0; i < n; i++) {
            //延对角线交换，不断的缩小
            for (int j = i; j < n; j++) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp;
            }
        }
    }
```
