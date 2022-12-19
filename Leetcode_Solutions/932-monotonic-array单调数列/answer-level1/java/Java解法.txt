执行用时 :2 ms, 在所有 Java 提交中击败了98.34%的用户
内存消耗 :48.2 MB, 在所有 Java 提交中击败了97.61%的用户

### 代码

```java
class Solution {
    public boolean isMonotonic(int[] A) {
        int len = A.length;
        if (len == 1) return true;
        if (A[0] > A[len-1]) {
            for (int i = 1; i < len; i++) {
                if (A[i]>A[i-1]) return false;
            }
        } else {
            for (int i = 1; i < len; i++) {
                if (A[i]<A[i-1]) return false;
            }
        }
        return true;
    }
}
```