```
class Solution:
    def permutation(self, S: str) -> List[str]:
        import itertools
        if len(S)==1:
            return [S]
        else:
            ans= list(itertools.permutations(list(S),len(S)))
            return list(map(lambda x:"".join(x),ans))
```
