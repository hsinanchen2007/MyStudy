### 解题思路
断点和字符长度之关系
### 代码

```python3
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        # 计算两个字符串从左到右的第一个不同点，称为断点
        def break_point(a, b, min_len):
            for i in range(min_len): 
                if a[i] != b[i]: return i
            return min_len
        # 计算两个字符串之长度，较大者称为max_len， 较小者称为min_len
        #短者用于循环
        min_len = min(len(first), len(second))
        #长者用于比较
        max_len = max((len(first), len(second)))
        # 计算左右断点
        break_point_left = break_point(first, second, min_len)
        break_point_right = break_point(first[::-1], second[::-1], min_len)
        # 如果相同则显然为真，否则根据左右断点之和+1应与最长者长度相等来判断
        return True if first==second else break_point_left + break_point_right +1 == max_len
```