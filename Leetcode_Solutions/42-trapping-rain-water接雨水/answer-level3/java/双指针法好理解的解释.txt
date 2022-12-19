在置顶的两个解法中都提到了朴素动态规划法的空间优化，也就是双指针法，我写一写自己的理解。

首先我们定义两个数组`int[] leftMax`和`int[] rightMax`，`leftMax[i]`表示位置`i`左边最高的柱子的高度（不包括`i`），`rightMax[i]`表示位置`i`右边最高的柱子的高度（不包括`i`）。

判断位置`i`处可以蓄水多少时，我们是根据公式`Math.max(0, Math.min(leftMax[i], rightMax[i]) - height[i])`来的。那么对于一个位置`i`，如果我们可以肯定`leftMax[i] < rightMax[i]`，那么就不用管`rightMax[i]`的值了，反之一样。

又注意到`leftMax[i]`从左到右是（不严格）递增的，`rightMax[i]`从右到左是（不严格）递增的，那么可以利用这个性质而施行上一段所述的方法。例如：

在`i` < `j`的前提下：
1. 若`leftMax[i] <= rightMax[j]`，因为`rightMax`的单调性，所以`rightMax[j] <= rightMax[i]`，故`leftMax[i] <= rightMax[i]`，我们可以确定位置`i`处的蓄水量。
2. 若`leftMax[i] > rightMax[j]`，因为`leftMax`的单调性，所以`leftMax[j] >= leftMax[i]`，故`leftMax[j] > rightMax[j]`，我们可以确定位置`j`处的蓄水量。

讲到这里，代码就是显然的了（Java），我们根据`leftMax[i]`和`rightMax[j]`的大小关系，要么确定位置`i`，要么确定位置`j`，`i`和`j`向中间汇合即可：

```java
class Solution {
    public int trap(int[] height) {
        int n = height.length;
        if (n <= 1) return 0;
        
        int sum = 0;
        int left = 1, right = n - 2;
        int leftMax = height[0];      // leftMax[left - 1]
        int rightMax = height[n - 1]; // rightMax[right + 1]
        while (left <= right) {
            if (leftMax <= rightMax) {
                // leftMax[left - 1] <= rightMax[right + 1] <= rightMax[left - 1]
                // thus the wall height is leftMax
                sum += Math.max(leftMax - height[left], 0);
                leftMax = Math.max(leftMax, height[left]);
                left++;
            } else { // leftMax > rightMax
                // rightMax[right + 1] < leftMax[left - 1] <= leftMax[right + 1]
                sum += Math.max(rightMax - height[right], 0);
                rightMax = Math.max(rightMax, height[right]);
                right--;
            }
        }
        
        return sum;
    }
}
```