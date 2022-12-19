### 解题思路
排序 比较相同索引差异
### 代码

```python
class Solution(object):
    def heightChecker(self, heights):
        heights_new = sorted(heights)
        count = 0
        for i in range(len(heights)):
            if  heights_new[i] != heights[i]:
                count += 1
        return count

```