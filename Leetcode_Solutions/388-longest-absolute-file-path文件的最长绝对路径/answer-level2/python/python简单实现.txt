```
class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        input = input.split('\n')
        res = 0
        stack = list()
        for i in input:
            d = i.count('\t')
            i = i[d:]
            while len(stack) > d:
                stack.pop()
            if '.' in i:
                cur = len(i) + len(stack)
                for s in stack:
                    cur += len(s)
                res = max(res, cur)
            else:
                stack.append(i)
        return res
```
