### 解题思路

![image](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png)
黑色的是柱子，蓝色的是水。
求最多能盛多少水。

## 解法

分水岭：比如从左往右遍历，只要找到第一个高度大于最左侧的柱子的，它就是分水岭，这时候就能确定前面的水位。然后后面的和前面的就没关系了，递归执行这个算法。

到最后一段，可能没有更高的柱子了，找不到分水岭，但是可以直接把数组前后颠倒（reverse），再递归调用一次就可以了。

### 代码

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        cnt = len(height)
        if cnt < 3: return 0
        if cnt == 3:
            if height[0] > height[1] < height[2]:
                return min(height[0],height[2]) - height[1]
            return 0
        for l in range(cnt):
            if height[l] > 0: break
        hl = height[l]
        cur = l + 1
        f = False
        v = 0
        while cur < cnt:
            if height[cur] < hl:
                f = True
            else:
                if f:
                    for i in range(cur-1, l, -1):
                        if height[i] < hl:
                            v += hl - height[i]
                return self.trap(height[cur:]) + v
            cur += 1
        height.reverse()
        return self.trap(height)
```

欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)