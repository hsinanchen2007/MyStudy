### 经验
for i in range(len(li)-1):
迭代得用下标。写成for i in li会发生奇怪的事。

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A) -> bool:
        # if A/3 is integer
        li = A
        if sum(li) % 3 != 0 :
            return False
        amount = sum(li)//3
        l = []
        e = 0
        for i in range(len(li)-1):
            e += li[i]
            if e == amount:
                l.append(e)
                e = 0
                if len(l) == 2 and i<len(li)-1:
                    ind = i+1
                    l.append( sum(li[ind:]) )   
        if len(l) < 3 : return False 
        else:return l[0] == l[1] == l[2]
        
```