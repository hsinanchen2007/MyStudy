# 快排
```
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        for (int i = m; i < m + n; ++i) {
            A[i] = B[i - m];
        }
        Arrays.sort(A);
    }
}
```
时间复杂度: O(klogk)
空间复杂度: O(logk), 假设用快排
k = m+n
# 归并
```
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int[] aff = new int[m];
        for (int i = 0; i < m; ++i) {
            aff[i] = A[i];
        }
        int lAff = 0;
        int lB = 0;
        for (int i = 0; i < m + n; ++i) {
            if (lAff >= m) A[i] = B[lB++];
            else if (lB >= n) A[i] = aff[lAff++];
            else if (aff[lAff] < B[lB]) A[i] = aff[lAff++];
            else A[i] = B[lB++];
        }
    }
}
```
时间复杂度: O(m+n)
空间复杂度: O(m)
# 逆向归并
```
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int rA = m - 1;
        int rB = n - 1;
        for (int i = m + n - 1; i >= 0; --i) {
            if (rA < 0) A[i] = B[rB--];
            else if (rB < 0) A[i] = A[rA--];
            else if (A[rA] > B[rB]) A[i] = A[rA--];
            else A[i] = B[rB--];
        }
    }
}
```
时间复杂度: O(m+n)
空间复杂度: O(1)