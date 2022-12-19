### 解题思路
range生成速度会比较快？
![image.png](https://pic.leetcode-cn.com/4563ad691dd2c5070f26688a77c3f732c23e23566a5838af737757e67bad2436-image.png)


### 代码

```python3
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        return list(range(1, 10**n))
```
