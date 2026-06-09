用的动态规划。

注意特殊情况。0行，1行，2行。

详细的解释在注释中。

```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        if numRows == 1:
            return [[1]]
        if numRows == 2:
            return [[1], [1, 1]]
        rows = [[1], [1, 1]]
        for i in range(3, numRows+1): # 从第3行开始
            rowi = [0] * i            # 第i行共有i个数字
            rowi[0] = 1               # 第一个和最后一个数字都是1
            rowi[-1] = 1
            # 从第i行的索引为1到到索引为i-2的数字（也就是第二个数字到倒数第二个数字） 
            for j in range(1, i-1):   
                # 每个数字都是上一行的同位置和同位置-1的数字之和。注意是i-2，因为第i行在rows里面的索引是i-1
                rowi[j] = rows[i-2][j-1]+ rows[i-2][j]  
            rows.append(rowi)         # 再把第i行添加到rows中
        return rows
                
            
            
```

                
            
            

