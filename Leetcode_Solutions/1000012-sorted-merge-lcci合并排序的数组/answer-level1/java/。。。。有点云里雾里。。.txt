### 解题思路
。。。。有点云里雾里。。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        if(n==0)
            return;
        for (int i = m,j=0; i < A.length; i++,j++)
            A[i] = B[j];
        Arrays.sort(A);
    }
}
```