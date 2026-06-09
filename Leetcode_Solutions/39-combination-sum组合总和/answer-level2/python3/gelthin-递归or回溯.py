### 解题思路

![题.PNG](https://pic.leetcode-cn.com/52d8a6db63bd13aae429adff7c1f44e9e0f6fc2dec51800edcd75c0613ce435b-%E9%A2%98.PNG)
之前自己瞎写的代码，一直无法去重。


参考了 liweiwei 的做法 [回溯算法 + 剪枝](https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/)
增加了一个 begin 变量控制搜索范围，终于解决了重复解的问题。

同时 一个 begin 变量也起到了 visited 数组的作用。


但个人感觉我下面的解法不同于其他人的解法， 更像是递归，而不是回溯 (dfs)。



### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(candidates, target, begin, n):
            if candidates[begin] > target:
                return []
            res = []
            for i in range(begin, n):
                rest = target - candidates[i]
                if rest > 0:
                    for x in dfs(candidates, rest, i, n):  # 这里加一个循环很奇怪啊
                        res.append([candidates[i]]+x)
                elif rest == 0:
                    res.append([candidates[i]])
            return res

        candidates.sort()
        n = len(candidates)
        return dfs(candidates, target, 0, n)

```