### 解题思路
流式解决方案

### 代码

```java
class Solution {
    public int[] sortedSquares(int[] A) {
      return Arrays.stream(A).map(i->i*i).sorted().toArray();
    }
}
```