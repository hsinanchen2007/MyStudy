### 解题思路
建立一個diction
裡面存放目前的殘差(key) 與走過的步伐(step)
當殘差與較小的平方數新殘差大於0則 檢查diction裡面是否出現過對應的key 等於新殘差
如果有 就比較現有存放的步伐與新對應的步伐誰比較小
當殘差與較小的平方數新殘差等於0
就輸出結果

### 代码

```python3
class Solution:
    def numSquares(self, n: int) -> int:

        base = int(sqrt(n))+1
        dic = {n:0, 0:n}
        for it in range(n):
            new_dic = {n:0, 0:n}
            for i in range(base-1, 0, -1):     
                val = i*i
                for key in dic:
                    residual = key - val
                    if residual > 0 :
                        if residual not in dic:
                            new_dic[residual] = dic[key] + 1
                        else:    
                            new_dic[residual] = min(dic[key] + 1, dic[residual]) 
                    if residual == 0 :
                        new_dic[0] = min(dic[key] + 1, dic[0]) 
                        return new_dic[0] 
            dic = new_dic.copy()
```