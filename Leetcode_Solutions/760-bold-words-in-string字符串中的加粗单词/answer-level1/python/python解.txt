### 解题思路
用数列记录需要更改的位置，再做遍历插入

### 代码

```python
class Solution(object):
    def boldWords(self, words, S):
        """
        :type words: List[str]
        :type S: str
        :rtype: str
        """
        slist = [0 for i in range(len(S))]
        
        for i in words:
            indi = True
            starnum = 0
            while indi:
                k = S[starnum:]
                try:
                    starnum += k.index(i)
                    wlen = len(i)
                    for j in range(starnum, wlen + starnum):
                        slist[j] += 1
                    starnum += 1
                except:
                    indi = False
        indicator = [1 if i > 0 else 0 for i in slist]
        del slist

        indicator.append(0)
        indicator.insert(0, 0)

        newSlist = []
        for e, i in enumerate(indicator[1:-1]):
            if i==1 and indicator[e]==0:
                newSlist.append('<b>')
            newSlist.append(S[e])
            if i==1 and indicator[e+2]==0:
                newSlist.append('</b>')
        newS = ''.join(newSlist)
        return newS
```