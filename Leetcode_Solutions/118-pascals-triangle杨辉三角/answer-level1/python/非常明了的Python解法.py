
```
```python 

class Solution(object):
    def generate(self, numRows):
        res = []
        for i in range(numRows):
            if i == 0:
                res.append([1])
            else:
                last_layer = res[i-1][:]
                last_layer.append(0)
                last_layer.insert(0,0)
                cur_layer = [last_layer[j] + last_layer[j+1] for j in range(i+1)]
                res.append(cur_layer)
        return res

```
