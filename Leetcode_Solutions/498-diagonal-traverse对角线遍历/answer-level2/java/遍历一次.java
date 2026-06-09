### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    /*
        分析遍历特点,可以看出,遍历方向的正反与索引和有关(行索引值+列索引值)的奇偶性有关,然后加上边         界情况,遍历路线大概出来:
        具体分为以下几种情况:
        int M = matrix.length;
        int N = matrix[0].length;
        m代表行 n代表列
        1:索引和是奇数:
            如果m==0,元素在第一行,往右走一步索引位置变为[0,n+1]
            如果m>0,n>0并且m<M-1元素往下走索引位置变为[m++,n--];
            如果n==0,表示在第一列元素往下走索引位置变为[m++,0]
            如果m=M-1,表示m在最后一行,所以需要调整位置,m保持不变n++,索引位置变为[m,n++]
        2: 索引是偶数的情况
            m==0,元素咋第一行,往右走一步索引位置变为[0,n+1];
            如果m>0,n>0并且n<N-1,元素往上移动[m--,n++]
            如果n==0表示在第一列,元素下走索引位置变为[m++,0]
            如果n=N-1,表示n在左后一列,需要调整位置n保持不变,索引位置变为[n,m++]
    */
    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix.length == 0) {
            return new int[0];
        }
        int M = matrix.length;
        int N = matrix[0].length;
        int m = 0, n = 0;
        int[] result = new int[M * N];
        for (int i = 0; i < result.length; i++) {
            result[i] = matrix[m][n];
            //索引和是偶数
            if ((m + n) % 2 == 0) {
                if (n == N - 1) {
                    //n在最后一列,索引变为[n,m++]
                    m++;
                } else {

                    if (m == 0) {
                        //元素在第一行,右移
                        n++;
                    } else {
                        //正常的移动
                        m--;
                        n++;
                    }
                }
            } else {//索引和是奇数
                if (m == M - 1) {
                    //元素在最后一行,索引变为[m,n++]
                    n++;
                } else {
                    if (n == 0) {
                        //元素在第一列,下移
                        m++;
                    } else {
                        //正常移动
                        n--;
                        m++;
                    }
                }
            }
        }
        return result;
    }
}
```