### 解题思路
两个矩形不重叠的条件，邻边不重叠即可；而两个矩形重叠的情况太多了，一一列举很可能会有遗漏，所以找不重叠的条件比较简单。

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(rec1[2]<=rec2[0] || rec2[2]<=rec1[0] || rec1[1]>=rec2[3] || rec2[1]>=rec1[3]);
    }
}
```