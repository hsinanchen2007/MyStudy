动态转移方程是：
是不是用到最后一根木板：

f(x) = f(x-1) //最大值么有用到最后一根木板
f(x) = max(最后一根木板与其他木板的搭配)  //用到了最后一根木板

最终解答是  f(x) = Matn.max(f(x-1),max(最后一根木板与其他木板的搭配) )

代码如下：


```
class Solution {
    public  int maxArea(int[] height) {
        return maxCount(height, height.length);
    }

    public  int maxCount(int[] height, int length) {
        if (length == 0)
            return 0;
        if (length == 1)
            return 0;
        if (length == 2)
            return Math.min(height[0], height[1]);
        int max = 0;
        int area = 0;
        for (int i = 0; i < length - 1; i++) {
            area = (length -1 - i) * Math.min(height[i], height[length - 1]);
            if (area > max)
                max = area;
        }
        max = Math.max(maxCount(height, length - 1), max);
        return max;
    }
}
```