### 解题思路
二次刷题 还是能做错 看来需要三刷 四刷 五刷 才能不犯错

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        //初始边界条件
        if (m == 0 || n == 0) {
            for (int i = 0; i < n; i++) {
                A[m+i] = B[i];
            }
        }

        int i       = m - 1;
        int j       = n - 1;
        int inIndex = m + n - 1;

        a : while (i >= 0) {
            while (j >= 0) {
                if (A[i] > B[j]) {
                    A[inIndex] = A[i];
                    inIndex--;
                    i--; 
                    continue a;
                } else {
                    A[inIndex] = B[j];
                    inIndex--;
                    j--;
                }
            }
            i--;
        }

        //如果此时j还没用完 赋值给数组的前半部分
        if (j >= 0) {
            for (int k = 0; k <= j; k++) {
                A[k] = B[k];
            }
        }
    }
}
```