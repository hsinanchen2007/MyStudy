![image.png](https://pic.leetcode-cn.com/b3e609f85f3a31dd9e779e01845b5d97c089730c9ef7bb1425bcec0783b440ab-image.png)
思路肯定是通过前两个点的斜率（(y1-y0)/(x1-x0)），来比对后面每个点和第一个点连线的斜率（(yi-y0)/(xi-x0)）
但是一定要转化为乘法，除法不仅要考虑分子为0，而且double类型也不精确。
即：(y1-y0)/(x1-x0) = (yi-y0)/(xi-x0)
即：(y1-y0)*(xi-x0) = (x1-x0)*(yi-y0)
```
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        //两个点直接返回true
        if (coordinates.length == 2) {
            return true;
        }
        for (int i = 1; i < coordinates.length; i++) {
            int r1 = (coordinates[1][1] - coordinates[0][1]) * (coordinates[i][0] - coordinates[0][0]);
            int r2 = (coordinates[i][1] - coordinates[0][1]) * (coordinates[1][0] - coordinates[0][0]);
            if (r1 != r2) {
                return false;
            }
        }
        return true;
    }
}
```
