解题思路：利用python内置函数进行排序，对比同样下标值不同的数据，相加。
代码：
```
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        count = 0
        sorted_list = sorted(heights)

        for i in range(len(heights)):
            if heights[i] != sorted_list[i]:
                count += 1
        return count

```
