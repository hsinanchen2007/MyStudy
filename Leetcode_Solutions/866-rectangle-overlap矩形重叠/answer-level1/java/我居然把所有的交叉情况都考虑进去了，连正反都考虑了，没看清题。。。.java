### 解题思路


### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if (((rec1[0] < rec2[0] && rec2[0] < rec1[2]) || (rec1[2] < rec2[0] && rec2[0] < rec1[0])) || ((rec1[0] < rec2[2] && rec2[2] < rec1[2]) || (rec1[2] < rec2[2] && rec2[2] < rec1[0])) ||
                ((rec2[0] < rec1[0] && rec1[0] < rec2[2]) || (rec2[2] < rec1[0] && rec1[0] < rec2[0])) || ((rec2[0] < rec1[2] && rec1[2] < rec2[2]) || (rec2[2] < rec1[2] && rec1[2] < rec2[0]))) {
            if ((rec2[1] < rec1[1] && rec1[1] < rec2[3]) || (rec2[3] < rec1[1] && rec1[1] < rec2[1])) {
                return true;
            }else if ((rec2[1] < rec1[3] && rec1[3] < rec2[3]) || (rec2[3] < rec1[3] && rec1[3] < rec2[1])) {
                return true;
            } else if ((rec1[1] < rec2[1] && rec2[1] < rec1[3]) || (rec1[3] < rec2[1] && rec2[1] < rec1[1])) {
                return true;
            }else if ((rec1[1] < rec2[3] && rec2[3] < rec1[3]) || (rec1[3] < rec2[3] && rec2[3] < rec1[1])) {
                return true;
            }
        }
        return false;
    }
}
```