### 解题思路


### 代码

```java
class Solution {
    public int repeatedNTimes(int[] A) {
        Set<Integer> s = new HashSet<Integer>();
        for (int i = 0; i < A.length; ++i) {
            if (!s.add(A[i])) {
                return A[i];
            }
        }
        return A[0];
    }
}
```