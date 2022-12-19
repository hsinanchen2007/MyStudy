### 解题思路
此处撰写解题思路
1. 首先要会写快排：需要设定一个标兵和左右两个指针，判断右指针是否大于标兵，再判断左指针是否小于标兵。目的是把标兵放到中间位置。
2. 再看K值是否与快排中的标兵位置相等。
### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        def sort(arr, l , r):
            val = arr[l]
            while l < r:
                while l < r and arr[r] >= val:
                    r -= 1
                if l < r:
                    arr[l] = arr[r]
                    l += 1
                while l < r and arr[l] <= val:
                    l += 1
                if l < r:
                    arr[r] = arr[l]
                    r -= 1
            arr[l] = val
            return l 
        def help(arr, l, r, k):
            dp = sort(arr, l, r)
            if dp == k:
                return
            elif dp > k:
                help(arr, l, dp-1, k)
            else:
                help(arr, dp+1, r, k)
            
        if len(arr) < 2 or len(arr) == k:
            return arr
        if k == 1:
            return arr[:k]
        help(arr, 0, len(arr)-1, k)
        return arr[:k]
```