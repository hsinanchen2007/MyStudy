### 解题思路
剑指offer面试题52，翻译过来的，
时间复杂度O(n)
把B[i] = A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]看成A[0]*A[1]*...*A[i-1]和A[i+1]*...*A[n-2]*A[n-1]两部分的乘积，B可以表示成矩阵。
定义C[i] = A[0]*A[1]*...*A[i-1]，
D[i] = A[i+1]*...*A[n-2]*A[n-1]，
C是左下三角，D是右上三角(倒三角)；
他们各自的推算公式是:
C[i] = C[i-1]*A[i-1]
D[i] = D[i+1]*A[i+1]
然后分别计算，再乘起来，不做优化的代码如下:

### 代码

```java
class Solution {
    public int[] constructArr(int[] a) {
        if (a == null || a.length == 0) {
            return new int[]{};
        }
        int length = a.length;
        int[] c = new int[length];
        int[] d = new int[length];
        int[] b = new int[length];
        c[0] = 1;
        for (int i = 1; i < length; i++) {
            c[i] = c[i - 1] * a[i - 1];
        }
        d[length - 1] = 1;
        for (int i = length - 2; i >= 0; i--) {
            d[i] = d[i + 1] * a[i + 1];
            b[i] = c[i] * d[i];
        }
        b[length - 1] = c[length - 1];
        return b;
    }
}
```

照着书上&别人的代码，小优化一下，减少不必要的数组内存分配:

```
class Solution {
    public int[] constructArr(int[] a) {
        if (a == null || a.length == 0) {
            return a;
        }
        int length = a.length;
        int[] c = new int[length];
        c[0] = 1;
        for (int i = 1; i < length; i++) {
            c[i] = c[i - 1] * a[i - 1];
        }
        double temp = 1;
        for (int i = length - 2; i >= 0; i--) {
            temp *= a[i+1];
            c[i] *= temp;
        }
        return c;
    }
}

```
