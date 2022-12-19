递归，记忆化搜索
```
class Solution:
    def __init__(self):
        self.result_dict = dict()

    def numWays(self, steps: int, arrLen: int) -> int:
        cnt = self.helper(steps, 0, arrLen, 0)
        return cnt % (10**9 + 7)

    def helper(self, step_sy, point_add, arrlen, count):
        if step_sy == 0 and point_add == 0:
            count += 1
            self.result_dict.update({(step_sy, point_add): count})
            return count

        if step_sy >= point_add and point_add < arrlen and point_add >= 0:
            if (step_sy-1, point_add) in self.result_dict:
                c1 = self.result_dict[(step_sy-1, point_add)]
            else:
                c1 = self.helper(step_sy-1, point_add, arrlen, count)
            if (step_sy-1, point_add+1) in self.result_dict:
                c2 = self.result_dict[(step_sy-1, point_add+1)]
            else:
                c2 = self.helper(step_sy-1, point_add+1, arrlen, count)
            if (step_sy-1, point_add-1) in self.result_dict:
                c3 = self.result_dict[(step_sy-1, point_add-1)]
            else:
                c3 = self.helper(step_sy-1, point_add-1, arrlen, count)
            self.result_dict.update({(step_sy, point_add): c1 + c2 + c3})
            return c1 + c2 + c3
        else:
            return count
```
