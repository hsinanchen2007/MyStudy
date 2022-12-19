```
class Solution:
    def largestPerimeter(self, A) -> int:
        a = len((A)) -1
        A = sorted(A)

        while a-2>=0:
            if A[a-1] + A[a-2] <= A[a]:
                a -= 1
                continue
            return A[a-1] + A[a-2] + A[a]

        return 0

```
从最后一个数开始往前推，可以减少计算量