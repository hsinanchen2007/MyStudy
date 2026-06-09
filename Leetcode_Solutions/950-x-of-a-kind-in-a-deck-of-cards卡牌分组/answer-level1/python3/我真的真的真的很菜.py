### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        if len(deck) < 2:
            return False
        dic = {}
        j = 0
        for i in range(0, len(deck)):
            j = dic.get(deck[i])
            if j == None:
                dic[deck[i]] = 1
            else:
                dic[deck[i]] += 1
        mcnt = 10000
        # 找出数量最少的
        for cnt in dic:
            if mcnt > dic[cnt]:
                mcnt = dic[cnt]
                k = cnt
        # 计算所有公约数hcf
        hcf = []
        for i in range(1, mcnt + 1):
            for key in dic:
                if dic[key] % i == 0:
                    hcf.append(i)
        #所有公约数出现的数量h
        h = {}
        for j in hcf:
            if j in h:
                h[j] += 1
            else:
                h[j] = 1
        #找最大公约数mkey
        mkey = 0
        for key in h:
            if h[key] == len(dic) and mkey < key:
                mkey = key
        if mkey == 1:
            return False
        return True
```