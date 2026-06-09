### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        def helper(arr, k):
            if k > len(arr) or k <= 0:
                return []
            pivot = arr[0]
            left = [num for num in arr[1:] if num <= pivot]
            right = [num for num in arr[1:] if num > pivot]
            if len(left) == k - 1:
                return left + [pivot]
            elif len(left) > k - 1:
                return helper(left, k)
            else:
                return left + [pivot] + helper(right, k - len(left) - 1)

        return helper(arr, k)
```