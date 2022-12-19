### 解题思路
pivot partition

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        # target index is k
        # quick sort

        size = len(arr)
        if size == 0 or size <= k:
            return arr
        left = 0
        right = size - 1
        while True:
            # print(arr)
            ind = self._partition(arr, left, right)
            

            if ind == k:
                return arr[:k]
            elif ind > k:
                right = ind - 1
            else:
                left = ind + 1
    
    def _partition(self, arr, left, right):
        pivot = arr[left]
        j = left
        for i in range(left+1, right+1):
            if pivot > arr[i]:
                j += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[left], arr[j] = arr[j], arr[left]
        return j

```