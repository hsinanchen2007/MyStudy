### 解题思路
思路很简单, 类似完全0-1背包, 这里用回溯实现
其中一个技巧是如何避免结果重复, 如[2,2,3], [2,3,2]
不用再新建一个set去判断了
只需多传入一个参数i, 代表当前选到了哪个元素,
因为是完全背包, 所以每次向下传仍传入i, 如果每个数只能选一次, 则传i+1

### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def solve(tar, path, res, i):
            if tar==0:
                res.append(path[:]) # append的是path的引用地址
                return 
            for i in range(i, l):# 从i开始
                if candidates[i]<=tar:
                    path.append(candidates[i])
                    solve(tar-candidates[i], path, res, i)#每个数可以多次选所以传i, 若只能选一次传i+1
                    path.pop()
        res = []
        l = len(candidates)
        solve(target, [], res, 0)
        return res
```