```java
class Solution {
    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        int[][] res = new int[R * C][2];
        res[0] = new int[]{r0, c0};
        int count = 1;
        int step = 0;
        int[] dirs = {0,1,0,-1,0};
        int dx = r0;
        int dy = c0;
        int k = 0;
        while (count < R * C) {
            if (k == 0 || k == 2) {
                step ++;
            }
            for (int i = 0; i < step; i ++) {
                dx += dirs[k];
                dy += dirs[k + 1];
                if (dx >= 0 && dx < R && dy >= 0 && dy < C) {
                    res[count][0] = dx;
                    res[count][1] = dy;
                    
                    count ++;
                }
            }
            k = (k + 1) % 4;
        }
        return res;
    }
}
```