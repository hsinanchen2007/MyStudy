### 解题思路
![image.png](https://pic.leetcode-cn.com/baeff7468784ec0dcce1bfbba94d7043d03a955c9e2f4d99a9d5758567394c5e-image.png)

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1: return [[1]]
        res = []
        for i in range(numRows):
            temp = [1] * (i+1)
            for j in range(1, i):
                temp[j] = res[-1][j-1] + res[-1][j] # -1表示上一行
            res.append(temp)
        return res

```