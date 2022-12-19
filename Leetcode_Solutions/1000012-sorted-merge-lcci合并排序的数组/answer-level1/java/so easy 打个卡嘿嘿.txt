### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        for(int i = 0; i < n; i++){
            A[m+i] = B[i];
        }
        Arrays.sort(A);
    }
}
```