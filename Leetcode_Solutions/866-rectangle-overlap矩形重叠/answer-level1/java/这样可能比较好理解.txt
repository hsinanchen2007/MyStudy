```
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int rec1_left = rec1[0];
        int rec1_down = rec1[1];
        int rec1_right = rec1[2];
        int rec1_up = rec1[3];

        int rec2_left = rec2[0];
        int rec2_down = rec2[1];
        int rec2_right = rec2[2];
        int rec2_up = rec2[3];

        if (rec1_right <= rec2_left || rec2_right <= rec1_left ||
                rec1_down >= rec2_up || rec2_down >= rec1_up) {
            return false;
        }
        return true;
    }
}
```
