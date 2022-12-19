这个图，将就着看吧。。数学解法就是：灰色部分+橘黄色部分-黄色-蓝色
此解法是以前刷题的时候，不知道是评论区还是题解区看到的，但是现在没找到，特别整理出来；
![接雨水三维.png](https://pic.leetcode-cn.com/7f5a6f748b5460430eb2a90fc180c9b85e2e892112943cdebb45bd0177be3780-%E6%8E%A5%E9%9B%A8%E6%B0%B4%E4%B8%89%E7%BB%B4.png)
```
class Trap {
    public int trap(int[] height) {
        int n = height.length;
        int curMax = 0, res = 0;
        for (int i = 0; i < n; i++) {
            curMax = Math.max(curMax, height[i]);
            //计算橘黄色部分
            res += curMax;
        }
        curMax = 0;
        for (int i = n - 1; i >= 0; i--) {
            curMax = Math.max(curMax, height[i]);
            //计算灰色部分，顺便减去蓝色
            res += curMax - height[i];
        }
        //减去黄色部分
        res -= curMax * n;
        return res;
    }
}
```
