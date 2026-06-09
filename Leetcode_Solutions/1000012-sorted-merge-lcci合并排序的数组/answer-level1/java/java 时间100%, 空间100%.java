![image.png](https://pic.leetcode-cn.com/f5d9822a63cdc1b0a0abb08dd9315a3d8712b84144edda604bda0538c3817ff9-image.png)
```
public void merge(int[] A, int m, int[] B, int n) {
    int i = A.length - 1;
    while (m > 0 && n > 0) {   // 从后往前扫描两个数组，哪个大就把它放到A数组的后面
        if (A[m-1] > B[n-1]) {
            A[i--] = A[m-- -1];
        } else {
            A[i--] = B[n-- -1];
        }
    }
    while (n > 0) {   // 最后B数组中如果没扫描完就依次扫描完放入到A数组中
        A[i--] = B[n-- -1];
    }
}
```
