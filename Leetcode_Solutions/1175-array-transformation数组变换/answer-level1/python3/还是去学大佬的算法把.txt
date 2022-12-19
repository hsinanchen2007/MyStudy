### 解题思路
照题翻译

### 代码

```python3
class Solution:
    def transformArray(self, arr):
        tmp = [0 for _ in range(len(arr))]
        for i in range(1,len(arr)-1):
            if arr[i-1]<arr[i] and arr[i]>arr[i+1]:
                tmp[i] = -1
            if arr[i-1]>arr[i] and arr[i]<arr[i+1]:
                tmp[i] = 1
        if tmp == [0 for _ in range(len(arr))]:
            return arr
        else:
            for i in range(len(arr)):
                arr[i] = arr[i]+tmp[i]
            self.transformArray(arr)
            return arr





```