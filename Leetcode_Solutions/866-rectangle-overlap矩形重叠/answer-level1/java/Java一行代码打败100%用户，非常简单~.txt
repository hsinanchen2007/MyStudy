🙋来打卡啦~矩形如果不重叠，从x轴和y轴上看两个矩形就变成了两条线段，这两条线段肯定是不相交的，也就是说左边的矩形的最右边小于右边矩形的最左边，也就是`rec1[2] < rec2[0] || rec2[2] < rec1[0]`；y轴同理，下面的矩形的最上边小于上面矩形的最下边，也就是`rec1[3] < rec2[1] || rec2[3] < rec1[1]`。因为题目要求重叠算相离，所以加上`=`，最后取反就行啦~

``` Java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0] || rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);
    }
}
```

另外推荐做相关题目：[合并区间](https://leetcode-cn.com/problems/merge-intervals/)，这题是多个一维区间的合并，是个面试热门题哦~

如果对你有帮助，记得点个赞哦亲~
