### 解题思路
回溯
 

### 代码

```python
class Solution(object):
    def combinationSum(self, candidates, target):
        """`内联代码`
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if not candidates:
            return candidates #如果candidates为空，直接返回

        size = len(candidates)
        tmp = [] #记录当前选择
        res = [] #记录结果
        candidates.sort() #对候选数组进行排序，为剪枝彻底

        def dfs(candidates, start, size, tmp, res, target):
            #当target值为0时，为所需要找的结果
            if target == 0:
                res.append(tmp[:])

            for i in range(start, size):
                remain = target - candidates[i] #当差值<0，进行剪枝
                if remain < 0:
                    break

                #进行回溯
                tmp.append(candidates[i])
                dfs(candidates, i, size, tmp, res, remain)
                tmp.pop()

        dfs(candidates, 0, size, tmp, res, target)
        return res

```