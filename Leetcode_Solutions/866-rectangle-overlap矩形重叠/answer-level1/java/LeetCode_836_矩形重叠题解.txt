### 解题思路

两个矩形的左下角都分别比另外一个矩形的右上角小

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return (rec1[2] > rec2[0]) && (rec1[3] > rec2[1]) && ((rec1[1] < rec2[3]) && (rec1[0] < rec2[2]));
    }
}
```