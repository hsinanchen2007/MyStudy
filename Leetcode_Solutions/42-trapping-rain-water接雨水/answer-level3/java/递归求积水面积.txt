### 解题思路
找出最高点的索引maxIdx， 然后从左边区域找出最高点索引maxLeftIdx，计算左边区域的积水面积；右边同理。


```java
// 计算左边的积水面积,先判断maxIdx - 1 > maxLeftIdx是否满足积水条件；
// 取决于短板，所以先减去用短板高度减去中间的高度
int ans = 0;
if (maxIdx - 1 > maxLeftIdx ) {
    for (int i = maxLeftIdx + 1; i < maxIdx; i++) {
        ans += (height[maxLeftIdx] - height[i]);
    }
}
```

### 代码

```java
class Solution {
   public int trap(int[] height) {
        int ans = 0;
        int len = height.length;
        if (len == 0 || len == 1) {
            return ans;
        }
        ans = getRainWater(height, 0, len - 1);
        return ans;
    }

    private int getRainWater(int[] height, int leftIdx, int rightIdx) {
        if (leftIdx + 1  >= rightIdx) {
            return 0;
        }
        int maxIdx = getMaxIdx(height, leftIdx, rightIdx);
        int maxLeftIdx = getMaxIdx(height, leftIdx, maxIdx - 1);
        int maxRightIdx = getMaxIdx(height, maxIdx + 1, rightIdx);
        int ans = 0;
        if (maxIdx - 1 > maxLeftIdx ) {
            for (int i = maxLeftIdx + 1; i < maxIdx; i++) {
                ans += (height[maxLeftIdx] - height[i]);
            }
        }
        if (maxRightIdx > maxIdx + 1) {
            for (int i = maxIdx + 1; i < maxRightIdx; i++) {
                ans += (height[maxRightIdx] - height[i]);
            }
        }
        ans += getRainWater(height, leftIdx, maxLeftIdx);
        ans += getRainWater(height, maxRightIdx, rightIdx);
        return ans;
    }

    private int getMaxIdx(int[] height, int startIdx, int endIdx) {
        int maxIdx = startIdx;
        for (int i = startIdx; i <= endIdx; i++) {
            if (height[i] > height[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }
}
```