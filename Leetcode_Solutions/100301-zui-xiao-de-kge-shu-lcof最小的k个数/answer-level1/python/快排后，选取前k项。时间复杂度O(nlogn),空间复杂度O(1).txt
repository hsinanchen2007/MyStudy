### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        length = len(arr)
        self.sort(arr, 0, length)
        return arr[0:k]

    def sort(self, arr, left, right):
        if left >= right - 1:
            return 
        temp = arr[left]
        i, j = left, right
        while i < j:
            while i < j:
                j -= 1
                if i == j or arr[j] < temp:
                    break
            if i != j:
                arr[i] = arr[j]

            while i < j:
                i += 1
                if i==j or arr[i] > temp:
                    break
            if i != j:
                arr[j] = arr[i]

        arr[i] = temp
        self.sort(arr, left, i)
        self.sort(arr, i+1, right)
```