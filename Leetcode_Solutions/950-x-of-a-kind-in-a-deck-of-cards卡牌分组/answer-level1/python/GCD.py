### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck):
        def gcd(a,b):
            while b>0:
                tmp = a%b
                a = b
                b = tmp
            return a
        dic = {}
        for i in range(len(deck)):
            if deck[i] not in dic:dic[deck[i]] = 1
            else:dic[deck[i]] += 1
        val = list(dic.values())
        if len(val)==1:return val[0]>1
        else:
            tmp = val[0]
            for i in range(1,len(val)):
                tmp = gcd(tmp,val[i])
            return tmp>1

```