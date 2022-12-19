使用并查集，先处理等式，将所有的相等的字符连通，然后处理不等式，检查是否出现矛盾。
在python3的提交中，时间上战胜了100%的用户。

```
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        alphabet = 'abcdefghijklmnopqrstuvwxyz'
        pre = {k:k for k in alphabet}
        for line in equations:
            a, b, eq = self.parse(line)
            if eq:
                pre[self.pre(pre, b)] = self.pre(pre, a)
        for line in equations:
            a, b, eq = self.parse(line)
            if not eq and self.pre(pre, a) == self.pre(pre, b):
                    return False
        return True
        
    def pre(self, dic, char):
        while dic[char]!=char:
            char = dic[char]
        return char
        
    
    def parse(self, equation):
        a = equation[0]
        b = equation[3]
        if equation[1] == '=':
            return a, b, True
        else:
            return a, b, False
```