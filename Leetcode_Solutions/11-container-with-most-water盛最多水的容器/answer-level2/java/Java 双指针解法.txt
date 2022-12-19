思路：

首先来看一下容器盛水容量如何计算？
指针`i`、`j` (`i<j`) 分别指向两条不同线时，那么`i`、`j`之间的盛水容量应该是 `Math.min(height[i], height[j]) * (j-i)`

接下来我们应该取`height[i]`和`height[j]`中的较短的那根线的下标往中间移动，重新计算新的容量与之前的容量进行大小比较。这里要注意为什么是取较短的那根线的下标往中间移动，因为下标往中间靠会导致宽度`(j-i)`变小，宽度减小的情况下，希望高度可以变高来弥补容量。

可以通过反证法看一下为什么不应该取`height[i]`和`height[j]`中的较长那根线的下标往中间移动：
假设 `height[i] < height[j]`，那么 `area = Math.min(height[i], height[j]) * (j-i) = height[i] * (j-i)`
下一步让较长的`height[j]`的下标`j`左移

1、如果`height[j-1] > height[j]`，那么容量`area = Math.min(height[i], height[j-1]) * (j-i-1) = height[i] * (j-i-1) < height[i] < (j-i)`（因为 `height[i] < height[j] < height[j-])`)
2、如果`height[j-1] < height[j]`，那么容量`area = Math.min(height[i], height[j-1]) * (j-i-1)` 此时取决于 `height[i]`, `height[j-1]` 之间的大小比较
    * 如果 `height[i] < height[j-1]`，那么容量 `height[i] * (j-i-1) < height[i] * (j-i)`
    * 如果 `height[i] > height[j-1]`，那么容量 `height[j-1] * (j-i-1) < height[i] * (j-i-1) < height[i] * (j-i)`
因此可以看出，如果让较长一根线的下标往中间移动，只会让盛水容量越变越小，这样就毫无意义了。

参考代码如下：

```java
/*
 * 执行用时：3 ms, 91.18%
 * 内存消耗：40.3 MB, 8.77%
 */
class Solution {

    public int maxArea(int[] height) {
        int max = 0, i = 0, j = height.length - 1;
        while (i < j) {
            max = Math.max(max, Math.min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return max;
    }
}
```