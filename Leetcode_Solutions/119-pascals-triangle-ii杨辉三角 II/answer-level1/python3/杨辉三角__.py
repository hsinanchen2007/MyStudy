### 解题思路
对每一行单独处理：首、尾分别添加一个0然后对应位置求和就可以得到新的一行。

只用设置一个列表`res`即可，每循环一次就覆盖`res`一次即可。最终循环结束，返回`res`即可。

### 代码

```python3
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [1]
        if rowIndex == 0:return res 
        for i in range(1,rowIndex+1):
            new_row = [a+b for a,b in zip([0]+res,res+[0])]
            res = new_row
        return res
```