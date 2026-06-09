```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        for d in candidates:
            if target > d:
                can = [i for i in candidates if i >= d]
                com = self.combinationSum(can, target - d)
                for i in com:
                    i.insert(0, d)
                ans.extend(com)
            if target == d:
                ans.append([d])
        return ans
```
