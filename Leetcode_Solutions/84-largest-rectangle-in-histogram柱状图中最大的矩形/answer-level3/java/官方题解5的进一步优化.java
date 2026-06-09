
在这种方法中，官方题解维护一个栈。需要n的空间复杂度，而这里只需利用heights[i] <= heights[i + 1]来判断是否要进行面积计算，就可以不需要使用栈。
代码很简单，可以考虑维护一个int类型的left变量来记录数组下降的点，下次计算面积时，判断条件j>=0可以优化为j>=left来实现完全意义的O(n)时间复杂度。
```java []
class Solution{
    public int largestRectangleArea(int[] heights) {
        int res = 0;
        int len, wid;
        for (int i = 0; i < heights.length; i++) {
            if(i != heights.length - 1 && heights[i] <= heights[i + 1]) continue;   //这一步的判断很玄妙
            wid = heights[i];
            for (int j = i; j >= 0; j--) {
                len = i - j + 1;
                wid = Math.min(wid, heights[j]);
                res = Math.max(res, len * wid);
            }
        }
        return res;
    }
}
```

复杂度分析

时间复杂度：O(n)。 与官方题解方法5基本一致，极端情况可能。

空间复杂度： O(1)。用来存放栈中元素。
