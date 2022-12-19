### 解题思路
根据题意，两矩形若能重叠，第一种rect2重叠在rect1上，则rect2的x1应小于rect1的
x2且rect2的x2应大于rect1的x1，且rect2的y1应该小于rect1的y2且rect2的y2应该大于rect1的y1；第二种rect1重叠在rect2上，亦然；
### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if(rec2[0] < rec1[2] && rec1[1] < rec2[3] && rec1[0] < rec2[2] && rec2[1] < rec1[3]) {
            return true;
        }else if(rec1[0] < rec2[2] && rec2[1] < rec1[3] && rec2[0] < rec1[2] && rec1[1] < rec2[3]) {
            return true;
        }
        return false;
    }
}
```