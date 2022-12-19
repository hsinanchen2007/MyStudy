第一次发题解，执行56ms，因为感觉写的比较简洁所以尝试发一下， 大佬们轻点
回溯两个点：
1.首先边界条件：ip的四个部分凑齐了
2.其次：考虑每个部分必须0~255之间，同时第一位必须大于0除非整个该部分为0
```
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def traceback(num:int, temp:str, s:str):
            if num==4 and not s:
                rec.append(temp[:-1])
                return
            for i in range(1,4):
                if i<=len(s) and int(s[:i])<=255 and (s[0]>'0' or s[:i]=='0'):
                    traceback(num+1,temp+s[:i]+'.', s[i:] if i<len(s) else "")
        rec = []
        if len(s)<=12:
            traceback(0, "", s)
        else:
            return []
        
        return rec
            
```

