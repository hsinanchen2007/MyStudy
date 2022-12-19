方法同之前的组合总和I,组合总和II.
题设已经给定了数字为`1--9`，于是我们只需遍历`1———9`[range(1,10)],不存在重复元素，因此将`backTracking(curList, i+1)`复制给回溯函数`backTracking(curList, index)`.

这里主要还是理解递归，代码如下：
```py
class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        res = []

        def backTracking(curList, index):
            # recursion terminate
            if len(curList) == k and sum(curList) == n:
                res.append(curList)
                return
            # precess in current level
            # drill down
            for i in range(index, 10):
                backTracking(curList + [i], i + 1)

        backTracking([], 1)
        return res
```
