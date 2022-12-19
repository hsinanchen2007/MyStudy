```
from functools import reduce
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == '':
            return []
        dict = {'2':['a','b','c'], '3':['d','e','f'], '4':['g','h','i'], '5':['j','k','l'], '6':['m','n','o'], 
            '7':['p','q','r','s'], '8':['t','u','v'], '9':['w','x','y','z']}
        d = []
        for dd in digits:
            d.append(dict[dd])
        fn = lambda x : reduce(lambda x, y: [i+j for i in x for j in y], x)
        return fn(d)
```
