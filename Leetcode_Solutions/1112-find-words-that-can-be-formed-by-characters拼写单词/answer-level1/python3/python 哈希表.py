### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        hashmap={}
        for i in chars:
            hashmap[i]=hashmap.get(i,0)+1
        res=0
        hashmap2=hashmap.copy()
        for word in words:
            flag=True
            for j in word:
                if not hashmap.get(j):
                    flag=False
                    break
                else:
                    hashmap[j]-=1
                    if hashmap[j]==0:
                        del hashmap[j]
            if flag:
                res+=len(word)
            hashmap=hashmap2.copy()
        return res
```