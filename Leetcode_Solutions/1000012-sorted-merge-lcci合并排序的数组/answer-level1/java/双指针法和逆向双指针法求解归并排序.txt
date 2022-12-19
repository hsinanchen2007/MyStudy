## 双指针法
```java
/**
     * 双指针法
     * 时间复杂度：O(m+n)
     * 空间复杂度：O(m+n)
     * 问题：未复用A的内存空间
     */
    public static void merge(int[] A, int m, int[] B, int n) {
        if (m == 0) {
            for (int k = 0; k < n; k++) {
                A[k] = B[k];
            }
            return;
        } else if (n == 0) {
            return;
        }

        int[] sort = new int[A.length];
        int i = 0, pa = 0, pb = 0;

        while (pa < m || pb < n) {
            if (pa == m) {
                sort[i] = B[pb];
                pb++;
            } else if (pb == n) {
                sort[i] = A[pa];
                pa++;
            } else if (A[pa] < B[pb]) {
                sort[i] = A[pa];
                pa++;
            } else {
                sort[i] = B[pb];
                pb++;
            }
            i++;
        }
        for (int k = 0; k < m + n; k++) {
            A[k] = sort[k];
        }
    }
```

## 逆向双指针法

```java
    /***
     * 逆向双指针法
     * 时间复杂度：O(m+n)
     * 空间复杂度：O(1)
     */
    public void merge_(int[] A, int m, int[] B, int n) {
        if (m == 0) {
            for (int i = 0; i < n; i++) {
                A[i] = B[i];
            }
            return;
        } else if (n == 0) {
            return;
        }
        int i = m + n - 1, pa = m - 1, pb = n - 1;

        while (pa >= 0 || pb >= 0) {
            if (pa == -1) {
                A[i] = B[pb];
                pb--;
            } else if (pb == -1) {
                A[i] = A[pa];
                pa--;
            } else if (A[pa] > B[pb]) {
                A[i] = A[pa];
                pa--;
            } else {
                A[i] = B[pb];
                pb--;
            }
            i--;
        }
    }
```