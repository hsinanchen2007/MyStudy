### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        arr = [i for i in range(n)]
        index = (m-1) % len(arr)
        while len(arr) != 1:
            arr.pop(index)
            index = (index + (m-1)) % len(arr)
        
        return arr[0]
```
使用Python中的数组.pop(index)法，先构建一个数组，然后计算下一个要删除的index，这就需要求模运算。

这个算法不是最优的，还需要想新的算法。

END.