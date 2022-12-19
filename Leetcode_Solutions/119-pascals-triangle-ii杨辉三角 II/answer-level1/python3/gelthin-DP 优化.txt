### 解题思路
我这里的写的方式不对，没有对应到 DP 优化
需要重写。

### 代码

```python3
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
        result = [1]
        for i in range(1, rowIndex+1):
            new_result = [None]*(1+i)
            new_result[0] = 1
            new_result[i] = 1
            j, k = 0, 1
            while k<i:
                new_result[k] = result[j] + result[k]
                j += 1
                k += 1
            result = new_result
        return result

```