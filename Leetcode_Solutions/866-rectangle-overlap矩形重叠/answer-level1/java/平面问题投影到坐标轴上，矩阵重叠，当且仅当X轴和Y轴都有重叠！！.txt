### 解题思路
此处撰写解题思路
在左边轴上，两个区间可能的情况如![下图](https://pic.leetcode-cn.com/f18724613610c917f869d48ac05b387cd1a2b448e3208cbc8dbe049f29b1e291.jpg)]([图片来源](https://leetcode-cn.com/problems/rectangle-overlap/solution/tu-jie-jiang-ju-xing-zhong-die-wen-ti-zhuan-hua-we/)),只需要计算出每一个坐标轴的重叠情况，然后&&就OK啦
### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
    boolean x_overlap = !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0]);
    boolean y_overlap = !(rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);
    return x_overlap && y_overlap;
    }
}
```