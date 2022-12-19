### 解题思路
先统计bulls再统计cows

### 代码

```python3
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        from collections import Counter
        bulls=0
        cows=0
        hashmap={}
        for i,j in zip(secret,guess):
            if i==j:
                bulls+=1
            elif i not in hashmap:
                hashmap[i]=1
            else:
                hashmap[i]+=1
        for i ,j in zip(secret,guess):
            if i!=j:
                if j in hashmap:
                    if hashmap[j]>0:
                        hashmap[j]-=1
                        cows+=1
        return str(bulls)+"A"+str(cows)+"B"
        
        
        
    
```