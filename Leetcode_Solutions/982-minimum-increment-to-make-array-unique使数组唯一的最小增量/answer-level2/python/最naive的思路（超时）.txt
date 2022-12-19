挑出重复的值，然后循环+1一直在原数组中寻找，找到就一直+1，找不到就插回去，计数count。（可以通过一些测试样例，但是大样本会超时。这只是个最简单的想法。。。。但是很耗时，大佬们可以优化一下吗。。）
```
import bisect
class Solution(object):
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        dict = {}
        stack = []
        new = []
        count = 0
        for i in range(len(A)):
            dict[A[i]] = dict.get(A[i], 0) + 1
            if dict[A[i]] > 1:
                stack.append(A[i]+1)
                count += 1
                dict[A[i]] -= 1
            else:
                new.append(A[i])
        new.sort()
        stack.sort()

        for i in stack:
            while i in new:
                i += 1
                count += 1
            bisect.insort(new, i)
        return count




```
