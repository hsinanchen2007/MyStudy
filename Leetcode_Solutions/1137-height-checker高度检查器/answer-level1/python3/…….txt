### 解题思路
题目花里胡哨……其实不就是排错位置的学生人数……

### 代码

```python3
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        res = 0

        sorted_stu = sorted(heights)
        n = len(heights)

        for i in range(n):
            if heights[i] != sorted_stu[i]:
                res += 1
        return res
```