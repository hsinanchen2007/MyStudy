O(n)，  递归下降， parser

语法
```
    expr -> item | item ',' expr
    item -> factor | factor item
    factor -> WORD | '{' expr '}'
```
python 代码

```python
import re
from collections import namedtuple

token = namedtuple('token', ['type', 'value'])


class parser:
    '''grammar
    expr -> item | item ',' expr
    item -> factor | factor item
    factor -> WORD | '{' expr '}'
    '''

    def __init__(self):
        left = r'(?P<LEFT>\{)'
        right = r'(?P<RIGHT>\})'
        word = r'(?P<WORD>[a-z]+)'
        comma = r'(?P<COMMA>\,)'
        blank = r'(?P<BLANK>\s)'
        self.pattern = re.compile('|'.join([left, right, word, comma, blank]))

    def match(self, tp):
        # print(self.lookahead.value)
        if tp == self.lookahead.type:
            val = self.lookahead.value
            try:
                self.lookahead = next(self.gen)
            except StopIteration:
                self.lookahead = None
            except Exception as e:
                print(e)
            return val
        else:
            raise Exception(f"[Error]: {tp} expected, got {self.lookahead.type}")

    def genToken(self, s):
        scanner = self.pattern.scanner(s)
        for i in iter(scanner.match, None):
            if i.lastgroup != 'BLANK':
                yield token(i.lastgroup, i.group(0))

    def parse(self, s):
        self.gen = self.genToken(s)
        self.lookahead = next(self.gen)
        st = self.expr()
        return sorted(list(st))

    def expr(self):
        ret = self.item()
        while self.lookahead and self.lookahead.type == 'COMMA':
            self.match('COMMA')
            ret = ret.union(self.item())
        return ret

    def item(self):
        ret = self.factor()
        while self.lookahead and self.lookahead.type in ['WORD', 'LEFT']:
            sufs = self.factor()
            new = set()
            for pre in ret:
                for suf in sufs:
                    new.add(pre+suf)
            ret = new
        return ret

    def factor(self):
        if self.lookahead.type == 'LEFT':
            self.match('LEFT')
            ret = self.expr()
            self.match('RIGHT')
            return ret
        return {self.match('WORD')}


class Solution:
    def braceExpansionII(self, expression):
        pr = parser()
        return pr.parse(expression)


if __name__ == '__main__':
    pr = parser()
    li = ["{a,b}{c{d,e}}", "{{a,z}, a{b,c}, {ab,z}}", "{a,b}c{d,e}f"]
    for i in li:
        print(pr.parse(i))

```