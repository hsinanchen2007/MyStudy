'''
插空法：70ms python
例如对于字符串：'()()'
要得到3对括号的字符串，即要插入一个'()'
这样就能保证字符串是有效的括号
另外减少重复项，则每次插入只能从最中间开始插入，
于是得到一系列结果：'()()()'、'()(())'、'()()()'
这样重复项占总体的约为 (n-1)/（n+1）！,n越大则重复率越低
重复项虽然不能完全除去，每次还需要集合来去除，但是重复项显然非常少，对效率的影响也就很小了。
'''
```
class Solution:
    def generateParenthesis(self, n: int) -> list:
        self.x = n
        res = set()
        temp= ['()']
        if n == 1:
            return temp
        if n == 0:
            return []
        temp = self.insertParen(temp, 1, 1)
        for i in temp: res.add(i)
        return list(res)
    def insertParen(self, s : list, locate : int, n) -> list:
        temp = set()
        cell = '()'
        for st in s:
            for ins in range(locate, len(st)+1):
                temp.add(st[0:ins]+cell+(st[ins:len(st)] if ins < len(st) else ''))
        if n < self.x-1:
            temp = self.insertParen(list(temp), locate+1, n+1)
        return temp
```


