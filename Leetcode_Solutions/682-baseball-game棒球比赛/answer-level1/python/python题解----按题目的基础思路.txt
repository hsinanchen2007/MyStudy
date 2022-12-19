```
class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        result = 0
        temp = []
        for i in ops:
            if i == '+':
                result += (temp[-1] + temp[-2])
                temp.append(temp[-1] + temp[-2])
            elif i == 'D':
                result += temp[-1]*2
                temp.append(temp[-1]*2)
            elif i == 'C':
                result -= temp[-1]
                temp.pop()
            else:
                result += int(i)
                temp.append(int(i))
        return result
```
