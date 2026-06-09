### 解题思路
从后向前合并即可

![image.png](https://pic.leetcode-cn.com/ac9ec9f3149dbe4d84abe471795c5378baba4fd182c5ba1b60b5890ba5e0aafb-image.png)

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int p = A.length - 1;
        int i = m - 1;
        int j = n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[p] = A[i];
                i--;
            } else {
                A[p] = B[j];
                j--;
            }
            p--;
        }
        if (j >= 0) {
            for (int k = 0; k <= j; k++) {
                A[k] = B[k];
            }
        }
    }
}
```