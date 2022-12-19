```
class Solution:
    def permutation(self, S: str) -> List[str]:
        res_list = []
        # 使用itertools.permutations生成各种组合，然后用set去重
        import itertools
        for x in set(itertools.permutations(S)):
            res_list.append("".join(x))
        return res_list
```
