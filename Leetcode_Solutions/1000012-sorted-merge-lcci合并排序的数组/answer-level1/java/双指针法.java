**解题思路**
将两个数组的元素进行比较，每次把较小的元素放入一个新的数组，直到最后，将A或B剩下的元素复制到C中，最后将C中排好序的元素再复制到A中。



```
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int[] C = new int[m + n];
        int i = 0, j = 0, k = 0;
        //比较两个数组的元素，把小的放在数组C中
        while (i < m && j < n) {
            if (A[i] < B[j]) {
                C[k++] = A[i++];
            } else {
                C[k++] = B[j++];
            }
        }
        //把A和B剩下的元素复制到C中
        while (i < m) C[k++] = A[i++];
        while (j < n) C[k++] = B[j++];
        //最后将排好序的C的元素复制给A
        if (m + n >= 0) System.arraycopy(C, 0, A, 0, m + n);
    }
}
```
