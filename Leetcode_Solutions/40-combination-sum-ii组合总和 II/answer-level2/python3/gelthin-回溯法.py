### 解题思路
+ 1.这里先对 candidates 进行排序，然后使用k来标记用到了第几个数，避免用了小数后又用大数。

+ 2.同时使用排列去重常用代码：candidates[i-1] == candidates[i] 来定一个顺序，避免 a1a2b, a2a1b 同时出现。
参考 [gelthin-递归解全排列-回溯-去重复](https://leetcode-cn.com/problems/permutation-ii-lcci/solution/gelthin-hui-su-pai-lie-qu-zhong-by-gelthin/)
#### 有了上面的 k 变量也需要用这里的排列去重。

[10,1,2,7,6,1,5]  -> [1a, 1b, 2, 5, 6, 7, 10] target = 8

+ 没有第 1 条会导致出现 [2,6] [6,2]
+ 没有第 2 条会导致出现 [1a, 7], [1b, 7]



### 代码

```python3
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(tmp, rest, k):  # 用 k 来标记 用到了第几个数，不要用前面的数，避免 [1,1,6] [1,6,1]
            if rest == 0:
                res.append(tmp)
            if rest<0:
                return
            for i in range(k, len(candidates)):
                if i>0 and candidates[i-1] == candidates[i] and not visited[i-1]:
                    continue
                elif not visited[i]:
                    visited[i] = True
                    dfs(tmp+[candidates[i]], rest-candidates[i], i+1)
                    visited[i] = False

        candidates.sort()
        visited = [False]*len(candidates)
        res = []
        dfs([], target, 0)

        return res
```