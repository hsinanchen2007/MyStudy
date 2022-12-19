### 解题思路

利用快排找到下标index， 使得index之前的数都比它小，当index==k时，找到最小k个数。

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k == 0:
            return []
        if k == len(arr):
            return arr
        def partition(left, right):
            pivot = arr[left]
            while left < right:
                while left < right and arr[right] >= pivot:
                    right -= 1
                arr[left] = arr[right]
                while left < right and arr[left] <= pivot:
                    left += 1
                arr[right] = arr[left]
            arr[left] = pivot
            return left
        left = 0
        right = len(arr) -1
        index = partition(left, right)
        while index != k:
            if index > k:
                right = index -1
                index = partition(left, right)
            elif index < k:
                left = index + 1
                index = partition(left, right)
        return arr[:k]
```