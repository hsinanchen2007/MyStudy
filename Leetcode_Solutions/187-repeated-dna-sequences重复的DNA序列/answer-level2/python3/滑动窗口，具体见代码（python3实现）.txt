### 解题思路
滑动窗口，具体见代码（python3实现）
### 代码

```python3
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        collec=set()
        answ=set()
        if len(s)<=10:
            return []
        for i in range(len(s)-9):
            if s[i:i+10] in collec:
                if s[i:i+10] not in answ:
                    answ.add(s[i:i+10])
            else:
                collec.add(s[i:i+10])
        return list(answ)
```