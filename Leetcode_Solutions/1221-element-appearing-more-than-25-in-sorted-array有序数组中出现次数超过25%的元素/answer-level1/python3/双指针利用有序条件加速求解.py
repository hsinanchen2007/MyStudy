本题与[删除排序数组中的重复项 (leetcode #26)](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)很相似。

```python
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        l = len(arr) // 4
        i = j = 0
        cnt = 0
        while j < len(arr):
            if arr[i] == arr[j]:
                if cnt == l:
                    return arr[i]
                cnt += 1
            else:
                i = j
                cnt = 1
            j += 1
```
假设数组长度为n，则时间复杂度： O(n)、空间复杂度：O(1)。

最小用时: 88 ms
