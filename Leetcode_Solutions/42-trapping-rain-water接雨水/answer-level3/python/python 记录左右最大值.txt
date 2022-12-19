### 解题思路
#### 1. 3次遍历

**min(当前节点左侧最大值, 当前节点右侧最大值) - 当前节点值**，即为当前节点可以存贮的水量。

**木桶效应：** 等同于 将 “当前节点的左侧最大值” 移到当前节点的左侧， “当前节点的右侧最大值” 移到当前节点的右侧，看成 “两边夹” 结构。

![image.png](https://pic.leetcode-cn.com/8465139331955e2ea2ab5c043805b788d745f68a727b059ca0d4dec75fb464d4-image.png)

### 代码

```python3
# -*- coding: utf-8 -*-

class Solution:
    def trap(self, height: List[int]) -> int:

        if not height:
            return 0

        sum_value = 0

        n = len(height)

        # 记录当前节点的整个左侧、整个右侧的最大值
        maxleft = [0] * n
        maxright = [0] * n 

        # 初始化
        maxleft[0] = height[0]
        maxright[-1] = height[-1]

        # 从左向右遍历，记录最大值
        for i in range(1, n):
            maxleft[i] = max(maxleft[i-1], height[i-1])

        # 从右向左遍历，记录最大值
        for i in range(n-2, -1, -1):
            maxright[i] = max(maxright[i+1], height[i+1])

        for i, v in enumerate(height):
            sum_value += max(0, min(maxleft[i], maxright[i])-v)

        return sum_value
```

#### 2. 动态规划，1次遍历

```python3
# -*- coding: utf-8 -*-

class Solution:
    def permute(self, height):
        if not height:
            return 0

        left, right = 0, len(height)-1
        max_left, max_right = height[left], height[right]
        res = 0

        while left <= right:
            if max_left < max_right:
                max_left = max(max_left, height[left])
                res += max_left - height[left]
                left += 1

            else:
                max_right = max(max_right, height[right])
                res += max_right - height[right]
                right -= 1        

        return res



if __name__ == '__main__':
    a = Solution()
    height = [0,1,0,2,1,0,1,3,2,1,2,1]
    print(a.permute(height))
```
