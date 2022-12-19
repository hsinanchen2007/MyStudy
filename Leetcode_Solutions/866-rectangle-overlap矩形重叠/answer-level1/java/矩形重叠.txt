### 解题思路
1.两个矩形看成两条线,rec1矩形的最右点小于rec2矩形的最左点,反之同理
2.rec1矩形的最高点小于rec2矩形的最地点,反之同理

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
return !(rec1[2]<=rec2[0]||rec2[2]<=rec1[0]||rec1[3]<=rec2[1]||rec2[3]<=rec1[1]);
    }
}
```