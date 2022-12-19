```
def commonChars(self, A: List[str]) -> List[str]:
    from functools import reduce 
    from collections import Counter 
    t = map(lambda x: Counter(x), A)
    t = reduce(operator.and_, t)
    ans = [ char for k, v in t.items() for char in k*v]
    return ans

    # one line
    # return [ char for k, v in reduce(operator.and_, map(lambda x: Counter(x), A) for char in k*v)]
```
