#python3 在每一步递归前查重（字典），用元组hash，用时104ms。
```python3 []
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        c = len(nums)
        if c == 1:
            return [nums]
        s = []
        d = [{} for i in range(c)]
        def pailie(s1, s2 = [], i = 0):
            if i == c:
                s.append(s2)
                return
            else:
                for j in s1:
                    f2 = s2[:]
                    f2.append(j)
                    b = tuple(f2)
                    e = d[i].get(b, 0)
                    if e == 0:
                        f1 = s1[:]
                        f1.remove(j)
                        d[i][b] = 1
                        pailie(f1, f2, i+1)
        pailie(nums)
        return s
```
