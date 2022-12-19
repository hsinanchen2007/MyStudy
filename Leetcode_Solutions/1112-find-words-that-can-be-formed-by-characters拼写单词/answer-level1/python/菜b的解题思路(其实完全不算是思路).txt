### 解题思路
两个字典比对

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        tempdict = {}
        length = 0

        for i in chars:
            if i not in tempdict.keys():
                tempdict.update({i:1})
            else:
                tempint = tempdict[i]
                tempint += 1
                tempdict.update({i:tempint})
        print(tempdict)

        
        for i in words:
            worddict={}
            dumpsign = 0
            for j in i:
                if j not in worddict.keys():
                    worddict.update({j:1})
                else:
                    tempint = worddict[j]
                    tempint += 1
                    worddict.update({j:tempint})
            print(worddict)
            for k in worddict.keys():
                if k not in tempdict.keys():
                    dumpsign = 1
                    break           
                if tempdict[k] >= worddict[k]:
                    continue
                else:
                    dumpsign = 1
            if dumpsign == 0:
                length += len(i)

        return length
```