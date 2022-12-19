### 解题思路
优化方向用Queue
### 代码

```python3
class Solution:
    def freqAlphabets(self, s: str) -> str:
            stmp = []
            res = ""
            for i in s:
                    if(i!='#'):
                            stmp+=[i]
                    else:
                                                    
                            tmp=stmp.pop()
                            tmp+=stmp.pop()
                            while(len(stmp)!=0):
                                j = stmp[0]
                                stmp = stmp[1:]
                                res+=chr(int(j)-1+ord('a'))
                            res+=chr(int(tmp[::-1])-10+ord('j'))
            while(len(stmp)!=0):
                j = stmp[0]
                stmp = stmp[1:]
                res+=chr(int(j)-1+ord('a'))
            return res

                
```