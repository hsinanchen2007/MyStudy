### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        def insertsort(L, star, end):
            for i in range(star+1, end):
                for j in reversed(range(star+1, i+1)):
                    if L[j] < L[j-1]:
                        L[j], L[j-1] = L[j-1], L[j]
        
        def merge(L, mid, star, end):
            temporary = []
            i = star
            j = mid
            while i < mid and j < end:
                if L[i] < L[j]:
                    temporary.append(L[i])
                    i += 1
                else:
                    temporary.append(L[j])
                    j += 1
            if i < mid: temporary.extend(L[i:mid])
            if j < end: temporary.extend(L[j:end])
            L[star:end] = temporary
        
        def mergesort(L, i, j):
            if j - i > 20 : #(len(nums) - 0 ) > 1 :长度大于1的时候继续split
                mid = (i+j) // 2
                mergesort(L, i, mid)
                mergesort(L, mid, j)
                merge(L, mid, i, j)
            else:
                insertsort(L, i, j)
        mergesort(nums, 0, len(nums))
        return nums

```