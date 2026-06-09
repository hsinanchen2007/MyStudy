

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int res = 0;
        for (int i = 0; i < A.length -1; i++) {
            if (A[i] >= A[i + 1]) {
                int temp = A[i] - A[i + 1] + 1;
                A[i + 1] = A[i] + 1;
                res += temp;
            }
        }
        return res;
    }
}
```