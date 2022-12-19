### 解题思路
此处撰写解题思路
![1581671890(1).png](https://pic.leetcode-cn.com/3843b21fb754b0f3330ef9c064d709240eb1c57c6b9945843dea3854369f56eb-1581671890\(1\).png)
hahhahahaahh太丢人了

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        length = len(s)
        # 空字符串或者numRows等于1
        if length == 0 or numRows == 1:
            return s
        numCols = 0
        # 计算列数
        n = length / (2*numRows-2)
        yu = length % (2*numRows-2)
        # 情况一：正好
        if yu == 0:
            numCols = int( n * (numRows-1) )
        elif yu <= numRows:
            numCols = int( n * (numRows-1) + 1 )
        else:
            numCols = int( n * (numRows-1) + yu - numRows )

        list = [[None for i in range(0,numCols)] for j in range(0,numRows)]

        # 计算出i元素放置的位置
        row = 0
        col = 0
        for i in range(0,length):
            list[row][col] = s[i]
            shang = 2 * numRows -2
            yu_2 = (i+1) % shang
            # 竖着的第一个元素
            if yu_2 == 0:
                row -= 1
                col += 1
            # 竖着的其他元素
            elif yu_2 < numRows:
                row += 1
            # 斜着的元素
            else:
                col += 1
                row = shang - yu_2

        # 输出
        result = ""
        k = 0
        num = 0
        for i in range(0,numRows):
            for j in range(0,numCols):
                # 已全部输出
                if num == length:
                    break
                if list[i][j] != None:
                    result += list[i][j]
                    k += 1
                    num += 1
            if j < numCols - 1:
                break

        return result
```