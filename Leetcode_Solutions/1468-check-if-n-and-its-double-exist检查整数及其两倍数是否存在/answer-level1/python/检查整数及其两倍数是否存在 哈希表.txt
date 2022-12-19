### 解题思路
对于一个数n,若n\n*2\n/2均不在字典中，则将其加入字典，对于相同数字，当且仅当n = 0时满足2倍关系

### 代码

```python
class Solution(object):
    def checkIfExist(self, arr):
        dic = {}
        for c in arr:
            if c not in dic:
                if c*2 not in dic:
                    if 1.0*c/2 not in dic:
                        dic[c] = 1
                    else:
                        return True
                else:
                    return True
            else:
                if c == 0:
                    return True
        return False
```