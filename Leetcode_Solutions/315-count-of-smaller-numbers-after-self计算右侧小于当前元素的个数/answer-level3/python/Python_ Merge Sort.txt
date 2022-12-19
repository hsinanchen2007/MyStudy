### 解题思路
直接从merge sort代码修改。
### 代码

```python
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n = len(nums)
        smaller = [0 for _ in range(n)]
    
        def sort(idx):
            if len(idx) < 2: return idx
            mid = len(idx) //2
            l, r = sort(idx[:mid]), sort(idx[mid:])
            return merge(l, r)

        def merge(a, b):
            m, n = len(a), len(b)
            c = []
            i, j = 0, 0
            while i < m and j < n:
                if nums[a[i]] > nums[b[j]]:
                    smaller[a[i]] += (n-j)
                    c.append(a[i])
                    i +=1
                else:
                    c.append(b[j])
                    j +=1
            if i == m: c += b[j:]
            else: c += a[i:]
            return c
        
        sort(list(range(n)))
        return smaller
    
```