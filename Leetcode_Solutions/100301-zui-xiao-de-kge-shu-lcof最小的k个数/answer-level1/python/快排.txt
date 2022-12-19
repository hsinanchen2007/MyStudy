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
        def partition(arr, low, high):
            pivot = arr[low]
            while low < high:
                while low < high and arr[high]>=pivot:
                    high -= 1
                arr[low] = arr[high]
                while low < high and arr[low]<=pivot:
                    low += 1
                arr[high] = arr[low]
            arr[high] = pivot
            return high
        low = 0
        high = len(arr) - 1
        p = partition(arr, low, high)
        while p != k-1:
            if p < k-1:
                low = p+1
                p = partition(arr, low, high)
            if p > k-1:
                high = p - 1
                p = partition(arr, low, high)
        return arr[:k]

```