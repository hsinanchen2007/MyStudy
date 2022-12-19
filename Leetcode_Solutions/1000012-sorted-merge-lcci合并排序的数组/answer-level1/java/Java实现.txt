### 解题思路
前两次没有考虑极端的情况，要引以为戒
遍历B数组，如果小于A数组中的某个元素，则赋值
A和B数组的遍历还有2出优化空间，明天补充

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        if (n == 0) {
            return;
        } else if (m == 0) {
            for (int i = 0; i < n; i++) {
                A[i]=B[i];
            }
            return;
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (B[i] >= A[m - 1]) {
                        A[m] = B[i];
                        m++;
                        break;
                    } else if (B[i] < A[j]) {
                        for (int k = m; k >= j+1; k--) {
                            A[k] = A[k-1];
                        }
                        A[j] = B[i];
                        m++;
                        break;
                    }
                }
            }
        }
    }
}
```