zz from StefanPochmann
```python
class Solution(object):
    def basicCalculatorIV(self, expression, evalvars, evalints):
        class C(collections.Counter):
            def __add__(self, other):
                self.update(other)
                return self
            def __sub__(self, other):
                self.subtract(other)
                return self
            def __mul__(self, other):
                product = C()
                for x in self:
                    for y in other:
                        xy = tuple(sorted(x + y))
                        product[xy] += self[x] * other[y]
                return product
        vals = dict(zip(evalvars, evalints))
        def f(s):
            s = str(vals.get(s, s))
            return C({(s,): 1}) if s.isalpha() else C({(): int(s)})
        c = eval(re.sub('(\w+)', r'f("\1")', expression))
        return ['*'.join((str(c[x]),) + x)
                for x in sorted(c, key=lambda x: (-len(x), x))
                if c[x]]
        
```
