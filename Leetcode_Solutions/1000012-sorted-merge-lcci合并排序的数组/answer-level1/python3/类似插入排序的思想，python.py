遍历B中的所有元素，只要找到元素应该插入的位置，然后将原本A从该位置起元素向后移动一位，然后把B的该元素插入A中
```
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        #把B的元素插入A即可
        for i in range(n):
            insert = m + i
            for j in range(m + i - 1, -1, -1):
                if B[i] < A[j]:
                    insert -= 1
                else:
                    break
            A[insert + 1:m + i + 1] = A[insert:m + i]
            A[insert] = B[i]
```
