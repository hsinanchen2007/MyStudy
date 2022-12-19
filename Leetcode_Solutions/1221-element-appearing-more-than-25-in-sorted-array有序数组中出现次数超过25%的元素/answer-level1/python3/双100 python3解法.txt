### 解题思路
计算超过25%的数，便是计算数组中重复次数最大的数，因为是一个非递减数组，所以利用值索引的减法就可以计算出重复次数，进而找出最大重复

### 代码

```python3
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        last = None
        index = []
        i = 0
        for v in arr:
            if last != v:
                index.append(i)
                last = v
            i += 1
        index.append(i)
        # return index
        result = -1
        Max = -1
        for i in range(len(index) - 1):
            if index[i + 1] - index[i] > Max:
                result = index[i]
                Max = index[i + 1]
        return arr[result]
```