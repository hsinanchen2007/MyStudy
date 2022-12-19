记住前一行的状态
### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if not numRows:
            return []
        pre_row = [1]
        res = [[1]]
        for i in range(1,numRows):
            tmp = [1]
            if len(pre_row)<2:
                tmp.append(1)
                res.append(tmp)
                pre_row = tmp
            else:
                for j in range(len(pre_row)-1):
                    tmp.append(pre_row[j]+pre_row[j+1])
                tmp.append(1)
                res.append(tmp)
                pre_row = tmp
        return res



```