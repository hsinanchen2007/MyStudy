### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isMonotonic(int[] A) {
        // 判断是递增还是递减
        boolean isUp = A[A.length - 1] - A[0] >= 0;
        int[] tmp = Arrays.copyOf(A, A.length);
        Arrays.sort(tmp);
        if (isUp) {
            for (int i = 0; i < tmp.length; i++) {
                if (A[i] != tmp[i]) {
                    return false;
                }
            }
            return true;
        } else {
            int length = A.length - 1;
            for (int i = 0; i < length; i++) {
                if (A[length - i] != tmp[i]) {
                    return false;
                }
            }

        }
        return true;
    }
}
```