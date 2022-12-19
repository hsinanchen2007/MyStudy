**1.初始两个指针i、j分别指向0和height.length - 1;
2.围成的面积取决于长 (j - i + 1) 和宽 min(height[i], height[j]) , 向中间夹逼时 (j - i + 1) 会减小但是 min(height[i], height[j]) 可能会增大；
3.应该在 height[i] 和 height[j] 中较小的一个值处进行++i或--j操作（短板效应因此在该处操作可能会得到比当前短板更大的height值）；**

```
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        for (int i = 0, j = (height.length - 1); i < j ; ) {
            int minHeight = height[i] < height[j] ? height[i ++] : height[j --];
            max = Math.max(max, (j - i + 1) * minHeight);
        }
        return max;
    }
}
```
