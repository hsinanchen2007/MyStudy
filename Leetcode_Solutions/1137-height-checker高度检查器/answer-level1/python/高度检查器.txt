![高度检查器.png](https://pic.leetcode-cn.com/e31e199ed503e53b9d38a0c2baf3d6003e1fb8c97298c5127de2a9fe9525a285-%E9%AB%98%E5%BA%A6%E6%A3%80%E6%9F%A5%E5%99%A8.png)

### 解题思路
1 对表示学生身高的数组排序，得到一个排序后的新数组。
2 对比排序后数组和原数组，记录下标值相同但元素值不同的下标个数，即为排错位置的学生个数。

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
# 复杂度分析
时间复杂度：O(NlogN)， python中排序所用蒂姆排序时间复杂度为O(NlogN),程序中所用循环时间复杂度为O(N),故总的时间复杂度为O(NlogN)。
空间复杂度：O(N),蒂姆排序为O(N),保存排序后数据的数组空间复杂度也为O(N)。