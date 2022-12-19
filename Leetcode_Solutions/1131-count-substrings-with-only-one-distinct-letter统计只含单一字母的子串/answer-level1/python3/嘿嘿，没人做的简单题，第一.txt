贴上我丑陋的代码：）
```python []
class Solution:
    def countLetters(self, S: str) -> int:
        cnt=1
        s=0
        for i in range(1,len(S)):
            if(S[i]==S[i-1]):
                cnt+=1                       #统计有几个字母相同
            else:
                s+=cnt*(cnt+1)/2       #等差公式求和
                cnt=1
        return int(s+cnt*(cnt+1)/2)#最后一个并不会自动加上
```