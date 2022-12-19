### 解题思路
使用二分法找到满足citations[i] >= len(citations)-i的最小i值，如果i为len(citations) - 1，通过判断citations[i]是否为0，返回0或者len(citations)-i。
![image.png](https://pic.leetcode-cn.com/29da53097eae0f6da91e3d044a38272bb409b3f7f7b46c946b49452f1b6a0e75-image.png)

### 代码

```python
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        if n == 0:
            return 0
        low = 0
        high = n - 1
        while low < high:
            mid = low + (high - low) / 2
            if citations[mid] >= n - mid:
                high = mid
            else:
                low = mid + 1
        if citations[low] == 0:
            return 0
        return n - low
```