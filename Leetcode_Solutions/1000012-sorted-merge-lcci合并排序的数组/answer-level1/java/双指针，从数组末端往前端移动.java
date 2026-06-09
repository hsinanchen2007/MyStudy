```
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int i = m - 1; 
        int j = n - 1;
        int k = m + n - 1;
        while(j >= 0) {
            if(i < 0) {
                while(j >= 0) {
                    A[k--] = B[j--];
                }
                return;
            }
            if(A[i] > B[j]) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        } 
    }
}
```
