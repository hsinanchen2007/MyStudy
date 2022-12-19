### 解题思路
我都佩服自己写的if判断了😁

### 代码

```java
class Solution {
     public int[] prevPermOpt1(int[] A) {
        if (A.length == 1)
            return A;
        int i;
        for (i = A.length - 1; i >= 0; i--) {
            if (i == 0)
                return A;
            if (A[i] < A[i - 1]) {
                break;
            }
        }
        i = i - 1;
        int len = A.length - 1;
        while (len > i) {
            if (A[len] >= A[i]) {
                len--;
                continue;
            }
            if (A[len] == A[len - 1]) {
                len--;
                continue;
            }
            break;
        }
        int temp = A[i];
        A[i] = A[len];
        A[len] = temp;
        return A;
    }
}
```