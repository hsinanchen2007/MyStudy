### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static int minIncrementForUnique(int[] A) {
        if (A.length < 2) {
            return 0;
        }
        int len = A.length;
        Arrays.sort(A);
        int pointer = A[0];
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] > pointer) {
                pointer = A[i] + 1;
                continue;
            }
            ans += pointer - A[i];
            pointer++;
        }
        return ans;
    }
}
```