### 解题思路
广度优先搜素

### 代码

```python3
from collections import defaultdict
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        manage = defaultdict(list)
        if n == 1:return 0
        for i in range(n):
            manage[manager[i]].append(i)
        stack = []
        stack.append((headID,0)) # (ID,minutes):通知到ID需要minutes时间

        maxConsuming = 0
        while stack:
            ID, consuming = stack.pop(0)
            if not manage[ID]:
                maxConsuming = max(maxConsuming,consuming)
            else:
                for nxt in manage[ID]:
                    stack.append((nxt,consuming+informTime[ID]))
        return maxConsuming
            

```
![image.png](https://pic.leetcode-cn.com/5ad97be449671c013d8060a49e3d0dd77f4724b4d901f0d0bdbf15a3902a2813-image.png)
