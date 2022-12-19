### 解题思路
![微信截图_20200408133355.png](https://pic.leetcode-cn.com/f66a3be78345fed3fcaed7f3a10f673740f26a635645240ff07cbe2681957d2a-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200408133355.png)
不好意思图有点糊。
思路就是找到那条分隔线（红色部分，数值为blockCount），在分隔线内的都是可以走到的，大于分隔线的坐标不进行匹配：）


### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        if (k == 0) {
            return 1;
        }

        int count = 0;
        // 横纵坐标位数相加值
        int mCount, nCount;
        // 阻塞数字，代表分割斜线（为一条封闭横纵坐标的斜线）上坐标值
        // 如果（当前行数+当前列数）%10==9(表示整个坐标系的分隔斜线)，则值=（当前行数+当前列数）
        int blockCount = 0;

        int row = 0, col;

        for (; row < m; row++) {

            // 如果当前（行数+列数）> 阻塞数字，则表示当前坐标在分隔线以外
            if (blockCount > 0 && row >= blockCount) {
                break;
            }

            mCount = row % 10 + row / 10 + row / 100;
            col = 0;

            for (; col < n; col++) {

                // 如果当前（行数+列数）> 阻塞数字，则表示当前坐标在分隔线以外
                if (blockCount > 0 && (row + col) >= blockCount) {
                    break;
                }
                nCount = col % 10 + col / 10 + col / 100;
                if (mCount + nCount <= k) {
                    count++;
                } else if ((row + col) % 10 == 9) {
                    // 如果（当前行数+当前列数）%10==9(表示整个坐标系的分隔斜线)，则值=（当前行数+当前列数）
                    blockCount = row + col;
                }
            }
        }

        return count;
    }
}
```