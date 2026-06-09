### 解题思路
速度有点慢。
这一题应该可以通过剪枝加速。


### 代码

```python3
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:

        def dfs(tmp, rest, begin):
            if len(tmp) > k or rest < 0:
                return
            if len(tmp) == k:
                if rest == 0:
                    res.append(tmp)
                else:
                    return

            for i in range(begin, 10):
                if i>rest: # 剪枝
                    break
                dfs(tmp+[i], rest-i, i+1)
        
        
        if n<k:
            return []
        res = []
        dfs([], n, 1)
        return res
```