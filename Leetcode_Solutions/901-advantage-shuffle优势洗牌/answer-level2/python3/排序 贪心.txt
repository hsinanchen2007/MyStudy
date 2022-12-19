先将A，B升序排序，然后遍历B中每个元素，如果A的最小值比当前值大，则放在这个元素对应的位置，否则，放到最后。
``` python
class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        A.sort()
        B = [(B[i], i) for i in range(len(B))]
        B.sort()
        i = 0
        j = len(B) - 1
        a = 0
        ans = [0] * len(B)
        while i <= j:
            if A[a] > B[i][0]:
                ans[B[i][1]] = A[a]
                i += 1
            else:
                ans[B[j][1]] = A[a]
                j -= 1
            a += 1
        return ans
    
```
