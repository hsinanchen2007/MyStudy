### 解题思路
反面思考。

### 代码

```java
class Solution {
    public boolean isRectangleOverlap2(int[] rec1, int[] rec2) {
        return false;
    }

    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0] || rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);
    }
}
```