### 解题思路
replace

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        size = 0
        for i in words:
            tmp = chars
            cnt = 0
            for j in i:
                if tmp.find(j) == -1:
                    break
                else :
                    cnt +=1
                    tmp = tmp.replace(j,'',1)
                    #print(tmp)
            if cnt == len(i):
                size = size + cnt
        return size
```