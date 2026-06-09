### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n < 1:
            return [""]
        tmp = {"()"}
        for i in range(1, n):
            cur = set()
            for s in tmp:
                temp = list(s)
                for i in range(len(temp)):
                    temp.insert(i, '()')
                    cur.add(''.join(temp))
                    temp.pop(i)
            tmp = cur
        return list(tmp)


```