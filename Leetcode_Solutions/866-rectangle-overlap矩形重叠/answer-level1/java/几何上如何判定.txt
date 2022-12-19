### 解题思路
    判定两个矩形是否重合，其实只要其中每个矩形的左下角点都在另外一个矩形右上角点的左下方就可以了。可以画图理解理解。

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
            if(rec1[0] < rec2[2] && rec1[1] < rec2[3] && rec2[0] < rec1[2] && rec2[1] < rec1[3])
            {   return true;    }
            return false;
    }
}
```