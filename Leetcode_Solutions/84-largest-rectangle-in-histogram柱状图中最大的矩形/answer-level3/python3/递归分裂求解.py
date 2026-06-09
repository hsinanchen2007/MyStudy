### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/cae4606c9ff997178c2f426546c8f6018b6ca91c56230db1221a0edc9d9d1242-image.png)

递归函数：
1、若当前是有序数组（正序/反序）：则遍历
2、若不是有序数组，找到最小值，算出最小值*区间，再左右分裂递归

### 代码

```python3
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        self.max_regoin = 0

        def find_max(left, right):
            if left < 0 or right > len(heights) or left >= right:
                return 0
            # 当前是否为有序数组
            if heights[left:right] == sorted(heights[left:right], reverse=False):
                for i in range(left,right):
                    new_regoin = heights[i] * (right - i)
                    if new_regoin > self.max_regoin:
                        self.max_regoin = new_regoin
                return
            elif heights[left:right] == sorted(heights[left:right], reverse=True):
                for i in range(right-1, left-1, -1):
                    new_regoin = heights[i] * (i - left + 1)
                    if new_regoin > self.max_regoin:
                        self.max_regoin = new_regoin
                return
            # 不是有序数组，继续分裂
            min_value = min(heights[left:right])
            min_index = left + heights[left:right].index(min_value)
            # print(left, right, min_index)
            # 比较当前
            new_regoin = min_value * (right - left)
            if new_regoin > self.max_regoin:
                self.max_regoin = new_regoin
            find_max(left, min_index)
            find_max(min_index+1, right)
            return
        find_max(0, len(heights))
        return self.max_regoin
```