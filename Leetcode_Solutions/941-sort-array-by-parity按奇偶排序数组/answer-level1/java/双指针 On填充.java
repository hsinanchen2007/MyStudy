### 解题思路
不考虑顺序可以使用双指针填充

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        // 既然不考虑顺序双指针填充
        int[] rs = new int[A.length];
        int x = 0, y = A.length - 1;
        for(int i = 0; i < A.length; ++i) {
            if ((A[i] & 1) == 1)
                rs[y --] = A[i];
            else
                rs[x ++] = A[i];
        }
        return rs;
    }
}
```