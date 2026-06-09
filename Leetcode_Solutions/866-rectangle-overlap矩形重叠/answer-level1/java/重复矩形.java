### 解题思路
排除一个矩形在另外一个矩形的左右上下侧即可

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(rec1[2] <= rec2[0] ||
                 rec1[0] >= rec2[2] ||
                 rec1[1] >= rec2[3] ||
                 rec1[3] <= rec2[1]);
    }
}
```