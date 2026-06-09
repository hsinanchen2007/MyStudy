### 解题思路
核心思想求出，出现次数为奇数的行，列 。
异或用来标记出现为奇数的位。

### 代码

```java
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        long x = 0;
        long y = 0;

        for (int[] index : indices) {
            x ^= 1L << index[0];
            y ^= 1L << index[1];
        }

        int x_com = countNumber(x);


        int y_com = countNumber(y);
        return x_com * m + y_com * n - 2 * x_com * y_com;
    }


    public static int countNumber(Long a) {
        int countx = 0;
        while (a != 0L) {
            countx++;
            a = a & (a - 1);
        }
        return countx;
    }
}
```