写了好半天，绕来绕去，可算绕出来了
保持单调递增，找到小于等于当前值最近的那个索引，在此之后所有子数组，最小值就是当前值
```
class Solution(object):
    def sumSubarrayMins(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        result = 0
        temp = []
        for index, i in enumerate(A):
            if not temp:
                temp.append((i, index, i))
            else:
                while temp and temp[-1][0] > i:
                    temp.pop()
                if not temp:
                    temp.append((i, index, i * (index + 1)))
                else:
                    temp.append((i, index, temp[-1][-1] + i * (index - temp[-1][1])))
            result += temp[-1][-1]
        return result % (10 ** 9 + 7)
```
