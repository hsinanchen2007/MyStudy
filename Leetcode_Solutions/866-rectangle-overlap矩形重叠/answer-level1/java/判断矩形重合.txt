### 解题思路
想知道两矩形是否重叠，那排除掉不重叠的情况即可。
1. 当图2整体在图1右边时候 或者 图1整体在图2右边时候 return false。
2. 当图2整体在图1下方时候 或者 图1整体在图2下方的时候 return false。
3. 其余的都是重叠场景 return true。

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int x11 = rec1[0];
        int y11 = rec1[1];
        int x21 = rec1[2];
        int y21 = rec1[3];

        int x12 = rec2[0];
        int y12 = rec2[1];
        int x22 = rec2[2];
        int y22 = rec2[3];

        if ( (x22 > x11 && x12 >= x21) || (x21 > x12 && x11 >= x22)){
            return false;
        }

        if ((y21 > y12 && y11 >= y22) || (y22 > y11 && y12 >= y21)){
            return false;
        }
        return true;
    }
}
```