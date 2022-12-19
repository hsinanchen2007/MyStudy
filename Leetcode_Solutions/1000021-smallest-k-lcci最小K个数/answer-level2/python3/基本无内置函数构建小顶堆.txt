### 解题思路
小顶堆

### 代码

```python3
class Solution:
    def smallestK(self, arr: List[int], k: int) -> List[int]:
        size = len(arr)
        arr = [0] + arr
        if k == 0:
            return []
        first_sort = size // 2

        for i in range(first_sort):
            self.heap_adjust(arr, first_sort-i, size)
        
        for i in range(k):
            arr[1], arr[size-i] = arr[size-i], arr[1]
            self.heap_adjust(arr, 1, size-i-1)

        return arr[-k:]

    def heap_adjust(self, arr, left, right):
        tmp = arr[left]

        i = left
        j = i * 2

        while j <= right:
            if j < right and (arr[j] > arr[j+1]):
                j += 1
            
            if tmp > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
                i = j
                j = i*2
            else:
                break
        arr[i] = tmp
```