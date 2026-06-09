### 解题思路
循环计数法

### 代码

```python3
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        if first == second:
            return True
        if len(first) - len(second) == 1:
            a = -1
            count = len(second)
            for i in second:
                for j in range(a+1,len(first)):
                    if i == first[j]:
                        a=j
                        count -= 1
                        break
            if count == 0 :
                return True
            else:
                return False
        elif len(second) - len(first) == 1:
            a = -1
            count = len(first)
            for i in first:
                for j in range(a+1,len(second)):
                    if i == second[j]:
                        a=j
                        count -= 1
                        break
            if count == 0 :
                return True
            else:
                return False
        elif len(second) == len(first):
            count = 0
            for i in range(len(second)):
                if second[i] != first[i]:
                    count += 1
            if count <= 1:
                return True
            else:
                return False
        else:
            return False
```