### 解题思路
写两个不同的字典，都加入进去，比较是否一致
不过不知道为什么居然没有 sorted(s1) == sorted(s2) 跑得快, 好吧.

### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        
        dicA = {}
        dicB = {}

        if len(s1) == len(s2):
            for i in s1:
                if i not in dicA:
                    dicA[i] = 1
                else:
                    dicA[i] += 1
            for i in s2:
                if i not in dicB:
                    dicB[i] = 1
                else:
                    dicB[i] += 1
            
            if dicA == dicB:
                return True
            else:
                return False
        
        return False
```