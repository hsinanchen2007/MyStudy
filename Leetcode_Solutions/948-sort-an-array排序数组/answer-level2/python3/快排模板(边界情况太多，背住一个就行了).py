```python

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        
        def quick_sort(q, l, r):
            if l >= r:
                return 
            i = l - 1
            j = r + 1
            x = q[l + r >> 1]
            while i < j:
                i += 1
                while q[i] < x:
                    i += 1
                j -= 1
                while q[j] > x:
                    j -= 1
                if i < j:
                    q[i], q[j] = q[j] , q[i]
            quick_sort(q, l, j)
            quick_sort(q, j + 1, r)

        quick_sort(nums, 0, len(nums) - 1)
        return nums

```