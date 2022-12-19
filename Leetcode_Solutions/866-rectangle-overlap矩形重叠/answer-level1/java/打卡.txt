### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if (Arrays.equals(rec1, rec2)) {
            return true;
        }
        long a1 = rec1[2] - rec1[0];
        long b1 = rec1[3] - rec1[1];
        long a2 = rec2[2] - rec2[0];
        long b2 = rec2[3] - rec2[1];
        long a3 = Math.max(Math.abs(rec1[0] - rec2[2]), Math.abs(rec2[0] - rec1[2]));
        long b3 = Math.max(Math.abs(rec1[1] - rec2[3]), Math.abs(rec2[1] - rec1[3]));
        if ((a3 >= (a1 + a2)) || (b3 >= (b1 + b2))) {
            return false;
        }
        return true;
    }
}
```