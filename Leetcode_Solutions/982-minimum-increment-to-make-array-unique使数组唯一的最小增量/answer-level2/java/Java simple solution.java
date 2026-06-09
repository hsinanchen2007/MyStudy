### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
  public int minIncrementForUnique(int[] A) {
    if (A.length == 0) return 0;

    Arrays.sort(A);
    int moves = 0;

    for (int i = 1; i < A.length; i++) {
      if (A[i] > A[i - 1]) continue;

      moves += A[i - 1] + 1 - A[i];
      A[i] = A[i - 1] + 1;
    }

    return moves;
  }
}
```