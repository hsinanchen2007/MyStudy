### 解题思路
和官方题解的思想一样。不过写法不太一样。还有可以优化的地方。
### 代码

```python
class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        s = sum(A)
        if s % 3 != 0:
            return False
        sub_s = s/3
        l = len(A)
        part1 = 0
        part2 = 0
        a = -1
        for i in range(l-2):
            part1 += A[i]
            if part1 == sub_s:
                a = i
                break
        if a < 0:
            return False
        else:
            for j in range(a+1,l-1):
                part2 += A[j]
                if part2 == sub_s:
                    return True
            return False 
            



```