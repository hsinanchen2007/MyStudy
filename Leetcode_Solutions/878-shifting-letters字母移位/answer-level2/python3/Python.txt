sum(shifts[i:])指的是字符串S中第i位上要增加的次数，但是由于每一次循环都要执行一次求和，效率比较低
```
class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        res=[]
        for i in range(len(S)):
            x=(ord(S[i])+sum(shifts[i:])-97)%26
            res.append(chr(x+97))   
        return ''.join(res)
```
稍稍修改一下sum操作，速度会快得多
```
class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        res=[]
        total=sum(shifts)
        for i in range(len(S)):
            x=(ord(S[i])+total-97)%26
            res.append(chr(x+97))   
            total-=shifts[i]
        return ''.join(res)
```

