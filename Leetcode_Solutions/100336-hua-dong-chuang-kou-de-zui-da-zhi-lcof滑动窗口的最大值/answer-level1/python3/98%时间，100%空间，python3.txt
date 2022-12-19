### 解题思路
![TIM截图20200225231413.png](https://pic.leetcode-cn.com/2efd30dd8582b8d8c5343ee8853a151cd9df80110376ba66beabca097d735668-TIM%E6%88%AA%E5%9B%BE20200225231413.png)

1. 判断新加入滑动窗口的值`nums[i+k]`是不是大于上一个滑动窗口的最大值`res[-1]`，如果是的话，直接在结果中加入`nums[i+k]`
2. 否则，判断一下滑动窗口刚刚丢弃的值`nums[i]`是不是就是`res[-1]`，如果是的话，计算出新滑动窗口的最大值，并加入结果，否则直接在结果加入`res[-1]`

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums: return []
        if k == 1: return nums
        res = [max(nums[:k])]
        for i in range(0, len(nums)-k):
            if nums[i+k] > res[-1]:
                res.append(nums[i+k])
            else:
                if nums[i] == res[-1]:
                    res.append(max(nums[i+1:i+k+1]))
                else:
                    res.append(res[-1])
        return res
```