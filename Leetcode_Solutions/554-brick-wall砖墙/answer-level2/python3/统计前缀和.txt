### 解题思路
注意不要将最后一列算上！

### 代码

```python3
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        if not wall:
            return 0

        maxLen=0
        d={}
        for l in wall:
            preSum=0
            for num in l[:-1]: #去除最后一列
                preSum+=num 
                d[preSum]=d.get(preSum, 0)+1
                maxLen=max(maxLen, d[preSum])
        return len(wall)-maxLen
```