```
# https://leetcode-cn.com/problems/find-positive-integer-solution-for-a-given-equation/
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        x = 1
        y = z
        f = customfunction.f
        res = []
        while True:
            if x == z + 1 or y == 0:
                return res
            if f(x, y) == z:
                res.append([x, y])
                x += 1
                y -= 1
            elif f(x, y) < z:
                x += 1
            else:
                y -= 1

```

