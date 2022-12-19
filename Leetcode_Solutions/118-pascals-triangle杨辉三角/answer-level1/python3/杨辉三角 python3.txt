### 解题思路
定义存储结果的列表res，然后遍历1-n
如果i==1，res.append([1])
如果i==2，res.append([1, 1])
如果i>2，我们定义一个temp列表作为res中第i个元素，然后遍历res的最后一个元素来确定temp
temp的首尾都为1
### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        for i in range(1, numRows+1):
            if i == 1:
                res.append([1])
            elif i == 2:
                res.append([1, 1])
            else:
                temp = []
                for j in range(1, i+1):
                    if j == 1 or j == i:
                        temp.append(1)
                    else:
                        temp.append(res[-1][j-1]+res[-1][j-2])
                res.append(temp)
        return res

```