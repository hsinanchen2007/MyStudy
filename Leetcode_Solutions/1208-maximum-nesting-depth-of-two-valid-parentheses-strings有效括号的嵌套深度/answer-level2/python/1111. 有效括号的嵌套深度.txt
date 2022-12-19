### 解题思路
主要是题目要理解，思路就是深度为奇数加入到A，偶数加入到B

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        if not seq:
            return 0
        res = []
        depth = 0
        for i in seq:
            if i =="(":
                depth += 1  
            if depth % 2 == 0:
                res.append(1)
            else:
                res.append(0)
            if i == ")":
                depth -= 1
        return res

```