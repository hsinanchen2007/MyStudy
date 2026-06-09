### 写在前面：
如果您觉得写得还可以，那就来关注在下的微信公众号吧“张氏文画”，不光有新鲜的 LeetCode 题解（多种思路，包教包会，开拓思维），还有经典的文章及短视频和大家分享，谢谢大家的关注！！！
![qrcode_for_gh_671e52fa1e78_258.jpg](https://pic.leetcode-cn.com/fa6a229fc23d58fb656a375382f96feecd9b6bc043183f36ee0d9ea9ffa3a12e-qrcode_for_gh_671e52fa1e78_258.jpg)

### 思路一：

双指针！！！

观察这个数组有什么特点，就像一个山峰一样。**在最大值左边不严格递增，右边不严格递减**。因此只需要把原数组变成符合这样要求的数组就行了，改变的量就是水量。

具体实现只需要先找到最大值索引，左右各自遍历一遍，**两边都维护一个值来表示之前的最大值以保证单调性**，如果比最大值小，水量就加上这个差值，如果大于等于，就更新最大值。

**非严格递增**：在这里就是允许存在``height[i]   =   height[i+1]``，但决不允许``height[i]   >  height[i+1]``。

### 代码：

时间复杂度O(n)，空间复杂度O(1)

```java
class Solution {
    public int trap(int[] height) {
        if (height == null || height.length == 0) {
            return 0;
        }
        int maxIndex = getMaxIndex(height);
        int maxArea = 0, current = height[0];
        // 遍历最大值左边，保证非严格递增
        for (int left = 1; left < maxIndex; left++) {
            if (height[left] < current) {
                maxArea += current - height[left];
            } else {
                current = height[left];
            }
        }
        // 遍历最大值右边（从右往左），保证非严格递增
        current = height[height.length - 1];
        for (int right = height.length - 2; right > maxIndex; right--) {
            if (height[right] < current) {
                maxArea += current - height[right];
            } else {
                current = height[right];
            }
        }
        return maxArea;
    }

    public int getMaxIndex(int [] height) {
        int index = 0, max = height[0];
        for (int i = 0; i < height.length; i++) {
            if (height[i] > max) {
                max = height[i];
                index = i;
            }
        }
        return index;
    }
}
```

### Result：

Runtime：1ms

Your runtime beats 100% of java submissions.