### 解题思路
有四种情况不重叠，返回取反。

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(rec2[1]>=rec1[3]||
                 rec2[3]<=rec1[1]||
                 rec2[2]<=rec1[0]||
                 rec2[0]>=rec1[2]);
    }
}
```