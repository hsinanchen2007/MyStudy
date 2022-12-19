```python3 []
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ca = sorted(candidates)
        ta = target
        s = [[] for i in range(ta+1)]
        def zuhe(ta):
            if ta in ca:
                s[ta].append([ta])
            for i in ca:
                if ta-i>=ca[0] and s[ta-i] != None:
                    for j in s[ta-i]:
                        k = sorted(j+[i])
                        if k not in s[ta]:
                            s[ta].append(k)
        for i in range(ca[0], ta+1):
            zuhe(i)
        return s[ta]
```