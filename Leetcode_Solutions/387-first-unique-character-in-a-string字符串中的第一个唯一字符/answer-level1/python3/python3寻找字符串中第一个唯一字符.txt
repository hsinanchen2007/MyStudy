```
class Solution:
    def firstUniqChar(self, s: str) -> int:
        if s=='':
            return -1
        dic={}
        ll = [1]*len(s)
        for i,ss in enumerate(s):
            if dic.get(ss)!=None:
                ll[dic[ss]]=0
                ll[i]=0
                dic[ss]=i
            else:
                dic[ss]=i
        for j in range(len(ll)):
            if ll[j]==1:
                return j
        return -1
```

![image.png](https://pic.leetcode-cn.com/b45bd6ab093d369e5a7db33d64b2f0aa0a9d8b03371bc21869e496c05ad7da38-image.png)

