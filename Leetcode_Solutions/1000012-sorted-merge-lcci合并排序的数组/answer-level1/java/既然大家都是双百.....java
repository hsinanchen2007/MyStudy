那我也来show一波

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int i = A.length-B.length-1;
        int j = B.length-1;
        int k = A.length-1;

        while (k>=0) {
            if ((i>=0 && j>=0 && A[i]>B[j]) || j==-1) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
        return;
    }
}
```