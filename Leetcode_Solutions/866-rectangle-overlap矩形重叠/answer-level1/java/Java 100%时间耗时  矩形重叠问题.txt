### 解题思路
反方向思考：怎样的情况下是没有重叠的？
我们在坐标图中画一个矩形，会发现：当另一个矩形在上/下/左/右则不会有重叠。
因此分析后结果如下：（编码）

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(rec1[2] <= rec2[0] || rec1[0] >= rec2[2]
              || rec1[3] <= rec2[1] || rec1[1] >= rec2[3]);
    }
}
```