### 解题思路
左右向中间移动，每次移动短的一边直到
发现比起始更长的边说明形成了一个沟，计算一遍雨水面积
否则累加阴影面积rocks用于计算
O(N) O(1)

### 代码

```java
class Solution {
    public int trap(int[] height) {

        if (height.length <= 2)
            return 0;
        int hIdx = 0, tIdx = height.length - 1, ret = 0;
        // 双指针，从左右向中间移动，直到相邻或相等
        while (hIdx < tIdx - 1) {
            int rocks = 0;
            // 每次选择短的一边移动
            if (height[hIdx] < height[tIdx])
                for (int i = hIdx + 1; i <= tIdx; i++) {
                    // 发现比当前边长时可以结算一次雨水面积
                    if (height[i] >= height[hIdx]) {
                        ret += height[hIdx] * (i - hIdx - 1) - rocks;
                        hIdx = i;
                        break;
                    // 否则累加低洼区域面积    
                    } else
                        rocks += height[i];
                }
            else
                // 从右向左，类似的
                for (int i = tIdx - 1; i >= hIdx; i--) {
                    if (height[i] >= height[tIdx]) {
                        ret += height[tIdx] * (tIdx - i - 1) - rocks;
                        tIdx = i;
                        break;
                    } else
                        rocks += height[i];
                }
        }

        return ret;
    }
}
```