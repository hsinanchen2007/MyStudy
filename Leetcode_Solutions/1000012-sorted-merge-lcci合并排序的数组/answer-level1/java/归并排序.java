### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = A.length - 1;
        while(j >= 0 && i >= 0) {
            if(A[i] >= B[j]) {
                A[k--] = A[i--];
            }else {
                A[k--] = B[j--];
            }
        }

        while(i >= 0) A[k--] = A[i--];
        while(j >= 0) A[k--] = B[j--];
    }
}
```