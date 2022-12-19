### 解题思路
注意下标的处理

### 代码

```python
class Solution(object):
    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        def partition(arr, left, right):
            key = arr[left]
            while left < right:
                while left < right and arr[right] >= key:
                    right -= 1
                arr[left] = arr[right]
                while left < right and arr[left] <= key:
                    left += 1
                arr[right] = arr[left]
            arr[left] = key
            return left
    
        if len(arr) == 0 or k <= 0:
            return []
        if len(arr) <= k:
            return arr
        low = 0
        high = len(arr)-1
        while low < high:
            index = partition(arr, low, high)
            if k < index:
                high = index-1
            elif k > index:
                low = index+1
            elif k == index:
                break
        return arr[:k]
```