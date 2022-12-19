### 解题思路
递归的模版：
candidates.sort()
n = len(candidates)
res = []
def backtrack(i, tmp_sum, tmp):
            if  tmp_sum > target or i == n:
                return 
            if tmp_sum == target:
                res.append(tmp)
                return 
            for j in range(i, n):
                if tmp_sum + candidates[j] > target:
                    break
                backtrack(j,tmp_sum + candidates[j],tmp+[candidates[j]])
backtrack(0, 0, [])
Return res


### 代码

```python
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        res = []
        s = candidates.sort()
        n = len(candidates)
        t = target
        def find_sum(i, tmp_sum, tmp):
            print i, tmp_sum, tmp
            if tmp_sum > target or i == n:
                return
            if tmp_sum == target:
                res.append(tmp)
                return

            for j in range(i, n):
                if tmp_sum + candidates[j] > target:
                    break
                find_sum(j,tmp_sum+candidates[j],tmp+[candidates[j]])

        find_sum(0, 0, [])
        print res
        return res
```