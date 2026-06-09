### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        n = [0,1]
        for i in range(len(cont)-1,-1,-1):
            if i == len(cont) - 1:
                n[0] = 1
                n[1] = cont[i]
            else:
                if cont[i] == 0:
                    tem = n[0]
                    n[0] = n[1]
                    n[1] = tem
                if cont[i] != 0:
                    n[0] = cont[i] * n[1] + n[0]
                    n[1] = n[1]
                    tem = n[0]
                    n[0] = n[1]
                    n[1] = tem
        
        tem = n[0]
        n[0] = n[1]
        n[1] = tem
        return n
```