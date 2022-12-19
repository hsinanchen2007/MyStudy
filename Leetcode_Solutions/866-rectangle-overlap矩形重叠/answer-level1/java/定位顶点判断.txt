### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        //只可能 1 包含 2
        if(rec1[2] < rec2[2]){
           int[] temp = rec1;
           rec1 = rec2;
           rec2 = temp;
        } 

        int x1 = rec1[0], x2 = rec1[2], y1 = rec1[1], y2 = rec1[3];
        int x3 = rec2[0], x4 = rec2[2], y3 = rec2[1], y4 = rec2[3];

        //包含
        if(x1 >= x3 && y1 >= y3 && x2 <= x4 && y2 <= y4)
            return true;

        //相交 1 在 2 的右上方， 即 2 的右上顶点 包含在 1 中
        if(y2 >= y4){
            if(x4 > x1 && y4 > y1)
                return true;
            return false;
        } 
        //相交 1 在 2 的右下方， 即 2 的右下顶点 包含在 1 中
        else {
            if(x4 > x1 && y3 < y2)
                return true;
            return false;
        }
    }
}



```