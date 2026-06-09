### 解题思路
先记录相同次数 将不同的颜色记录到两个字典中，最后进行比较取值

### 代码

```python
class Solution(object):
    def masterMind(self, solution, guess):
        G,g = 0,0
        dic1 = {}
        dic2 = {}
        for i in range(4):
            if solution[i] == guess[i] :
                G += 1
            else:
                if solution[i] not in dic1:
                    dic1[solution[i]] = 1
                else:
                    dic1[solution[i]] += 1
                if guess[i] not in dic2:
                    dic2[guess[i]] = 1
                else:
                    dic2[guess[i]] += 1
        for c in dic2:
            if c in dic1:
                g += min(dic1[c],dic2[c])
        return [G,g]
```