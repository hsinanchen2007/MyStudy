一开始想到的无疑就是暴力破解了（滑稽）

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        for i, first in enumerate(height):
            for j, second in enumerate(height):
                max_area = max_area if max_area > min(first, second) * abs(i - j) else min(first, second) * abs(i - j)
        return max_area
```

果然遇到了超时
 42 / 50 个通过测试用例
 43 号测试用例长度 5000

稍微看了一下官方的解答，有了下面的代码

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        left_index = 0
        right_index = len(height) - 1
        while left_index < right_index:
            new_area = min(height[left_index], height[right_index]) * abs(right_index - left_index)
            max_area = max_area if max_area > new_area else new_area
            # 往高度高的那个方向缩圈(滑稽)
            if height[left_index] < height[right_index]:
                left_index += 1
            else:
                right_index -= 1
        return max_area
```

运行结果

```
执行用时 :252 ms, 在所有 python3 提交中击败了18.62% 的用户
内存消耗 :15.2 MB, 在所有 python3 提交中击败了5.18%的用户

执行用时 :212 ms, 在所有 python3 提交中击败了25.18% 的用户
内存消耗 :15.4 MB, 在所有 python3 提交中击败了5.18%的用户

执行用时 :152 ms, 在所有 python3 提交中击败了89.01% 的用户
内存消耗 :15.3 MB, 在所有 python3 提交中击败了5.18%的用户
```

卧槽这测试速度怎么越来越快额（-_-||）
欢迎来github上看更多题目的解答[力扣解题思路](https://github.com/WRAllen/LeetCode)