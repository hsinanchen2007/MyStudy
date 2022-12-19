### 解题思路
本来想对子串k排序，然后替换的方式，结果超时了，干脆就用快排解决了。

执行用时 :600 ms, 在所有 Python3 提交中击败了6.44%的用户
内存消耗 :14.5 MB, 在所有 Python3 提交中击败了100.00%的用户

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        self.myQuickSort(arr, 0, len(arr)-1)
        return arr[:k]

    def myQuickSort(self, arr, low, high):
        if low>=high:
            return
        i = low
        j = high
        key = arr[i]
        while i<j:
            while j>i and arr[j]>=key:
                j -= 1
            arr[i] = arr[j]
            while i<j and arr[i]<=key:
                i += 1
            arr[j] = arr[i]
            arr[i] = key
            
        self.myQuickSort(arr, low, i-1)
        self.myQuickSort(arr, i+1, high)
```