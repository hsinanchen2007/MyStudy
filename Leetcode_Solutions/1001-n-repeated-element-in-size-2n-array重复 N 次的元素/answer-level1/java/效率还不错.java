### 解题思路
题目写的很清楚，总共2N个，N+1个不同，也就是说只要有一个重复的就是满足题目的结果，所以用了Set判重复

### 代码

```java
class Solution {
    public int repeatedNTimes(int[] A) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < A.length; i++) {
            if (set.contains(A[i])) {
                return A[i];
            } else {
                set.add(A[i]);
            }
        }
        return -1;
    }
}
```