### 解题思路
先做排序，后切片。2行代码搞定。

### 代码

```python
class Solution(object):
    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        arr.sort()
        return arr[0:k]
```