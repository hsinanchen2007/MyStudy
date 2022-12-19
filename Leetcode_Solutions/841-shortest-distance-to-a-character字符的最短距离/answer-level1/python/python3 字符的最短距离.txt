遍历一遍字符串，对于每个字符，同时向左向右寻找C，任意一边找到返回即可


```
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        n = len(S)-1
        res = []
        for i in range(n+1):     #遍历字符串
            x = 0
            while True:
                if 0<=(i-x)<=n:         #判断左查找索引是否存在
                    if S[i-x] == C:
                        res.append(x)
                        break
                if 0<=(i+x)<=n:         #判断右查找索引是否存在
                    if S[i+x] == C:
                        res.append(x)
                        break
                x += 1
        return res
```
