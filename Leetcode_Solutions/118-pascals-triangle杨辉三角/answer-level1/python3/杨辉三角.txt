### 解题思路
1.先判断三种情况（numRows = 0/1/2）
2.result 为结果列表先填写前两行内容，temp为每一行的列表
3.从result第三行开始遍历，每一行的第一个和最后一个元素填1，其他数字为上一行的相邻两个数字相加

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result = [[1],[1,1]]
        if numRows == 0:
            return []
        elif numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1],
                    [1,1]]
        else:
            for i in range(2,numRows):
                temp = [1]
                for j in range(1,i):
                    temp.append(result[i-1][j-1]+result[i-1][j])
                temp.append(1)
                result.append(temp)
            return result
```