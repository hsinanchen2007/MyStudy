```
import java.util.*;
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int l =0;
        int r = 0;
        int index = 1;
        while(l < n / 2) {
            int down = l;
            int up = n - 1 - l;
            //上层向右
            while(r < up) {
                result[l][r] = index;
                index++;
                r++;
            }
            //右层向下
            while(l < up) {
                result[l][r] = index;
                index++;
                l++;
            }
            //下层向左
            while(r > down) {
                result[l][r] = index;
                index++;
                r--;
            }
            //左层向上
            while(l > down) {
                result[l][r] = index;
                index++;
                l--;
            }
            l++;
            r++;
        }
        if(index == n * n) {
            result[l][r] = index;
        }
        return result;

    }
}
```
