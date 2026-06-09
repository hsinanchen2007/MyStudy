算法思路：
先找上坡，后找下坡，用mid记录山顶位置。
新山脉的起点为下坡的终点
```
class Solution(object):
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        res = 0
        i = 0
        while i < len(A):
            j = i
            # 找到上升的终点，即山顶
            while j + 1 < len(A) and A[j] < A[j+1]:
                j += 1
            mid = j
            # 找到下降的终点
            while j + 1 < len(A) and A[j] > A[j+1]:
                j += 1
            # 判断是否构成山脉
            if i < mid < j:
                res = max(res, j-i+1)
            # 如果是平山，i后移一位，否则下降的终点作为新的起点
            if i == j:
                i +=1
            else:
                i = j
        return res
```