### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        # 不可能超过 上边界
        # 显然时间复杂度太高
        res = []
        upper = target // 2 + 1
        t = target
        while upper > 0:
            end = upper
            path = []
            target = t
            while end >= 1:
                path.append(end)
                target -= end
                if target < 0:
                    break
                if 0 == target:
                    res.insert(0,path[::-1])
                    break
                end -= 1
            upper -= 1
        return res
```