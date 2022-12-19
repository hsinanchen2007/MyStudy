乏善可陈。

整道题目的代码如下：

```python
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if len(digits) == 0:
            return []

        def cate(l1, l2):
            res = []
            for i in range(len(l1)):
                for j in range(len(l2)):
                    res.append(l1[i] + l2[j])
            return res

        res = ['']

        map = {2: 'abc', 3: 'def', 4: 'ghi', 5: 'jkl',
               6: 'mno', 7: 'pqrs', 8: 'tuv', 9: 'wxyz'}

        for i in range(len(digits)):
            s = list(map[int(digits[i])])
            res = cate(res, s)

        return res
```

