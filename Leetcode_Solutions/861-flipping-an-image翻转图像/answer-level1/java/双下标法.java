### 解题思路
双下标法，注意判断添加上等于号，为了进行01反转操作

### 代码

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int n = A.length;
        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = n - 1;
            while (start <= end) {
                int temp = A[i][start];
                A[i][start] = reverse01(A[i][end]);
                A[i][end] = reverse01(temp);
                start++;
                end--;
            }
        }
        return A;
    }

    public int reverse01(int num) {
        return num == 0 ? 1 : 0;
    }
}
```