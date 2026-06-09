### 解题思路
n的结果可由n-1的结果获得


### 代码

```python3
class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n == 0:
            return [0]
        res = [0, 1]
        temp = 1
        while temp < n:
            i = 0
            while i < len(res):
                if (i / 2)%2 == 0: res.insert(i+1, 2**temp+res[i])
                else: res.insert(i, 2**temp+res[i])
                i += 2
            temp += 1
        return res

```