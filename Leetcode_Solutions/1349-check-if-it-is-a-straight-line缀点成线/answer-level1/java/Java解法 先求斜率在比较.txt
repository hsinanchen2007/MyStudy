1. 两点确定一条直线，少于等于两个点直接返回 true
2. 根据前两个点求出斜率；
2. 遍历比较后面的点和第一个点的斜率是否与第二步骤求出的斜率相等；
3. 如果有一次斜率不等，即有点不在直线上；
```
class Solution {
    public boolean checkStraightLine(int[][] nums) {
        if (nums.length <= 2) {
            return true;
        }
        int x1 = nums[0][0], y1 = nums[0][1];
        int x2 = nums[1][0], y2 = nums[1][1];
        double k = (double) (y2 - y1) / (x2 - x1);

        for (int i = 2; i < nums.length; i++) {
            int x3 = nums[i][0];
            int y3 = nums[i][1];
            double kt = (double) (y3 - y1) / (x3 - x1);
            if (k != kt) {
                return false;
            }
        }
        return true;
    }
}
```
