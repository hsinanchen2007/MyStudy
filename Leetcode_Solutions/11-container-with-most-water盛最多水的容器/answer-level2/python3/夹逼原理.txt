### 解题思路

>首先让我们联想一下`木桶效应`，水桶中的高度取决与最短的那块板，我们这里也是如此，但是略微有点不同的是，我们这个桶只有两块板子，而我们每次往中间移动短板的目的，是找一个比之前短板更长一点的短板，这样不就可以盛的水更多一点了吗


用所给的测试样例：
* 暴力法需要81次才能找到最大值
* 夹逼原理只需要8次即可找到最大值

结果：
![image.png](https://pic.leetcode-cn.com/62c81f0ac01b58b61c3ad650a7ff7d6392a90f21a75b34a464796dea2692a6d6-image.png)


### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 使用while循环：
        left_idx = 0
        right_idx = len(height) - 1
        areas = []

        while left_idx < right_idx:
            w = right_idx - left_idx
            if height[left_idx] < height[right_idx]:
                h = height[left_idx]
                # 左边短的向中间移动，注意此时右边并没有移动
                left_idx += 1
            else:
                h = height[right_idx]
                # 右边短的向中间移动，注意此时左边的没有移动
                right_idx -= 1
            area = w*h
            areas.append(area)
        return max(areas)
      
```

ps：夹逼原理名字是我瞎起的