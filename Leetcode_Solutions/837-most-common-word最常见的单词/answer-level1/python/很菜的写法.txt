### 解题思路
很菜的写法，写的很长，优点是超过了78.51%的用户

### 代码

```python3
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = paragraph.replace('!', ' ')
        paragraph = paragraph.replace('?', ' ')
        paragraph = paragraph.replace(',', ' ')
        paragraph = paragraph.replace(';', ' ')
        paragraph = paragraph.replace('.', ' ')
        paragraph = paragraph.replace("'", ' ')
        while paragraph.find("  ") >= 0:
            paragraph = paragraph.replace('  ', ' ')
        temp = paragraph.split(' ')
        new = list([i.lower() for i in temp])
        set_, max_, ret = {}, 0, 0
        for i in new:
            if i not in banned:
                if i not in set_:
                    set_[i] = 1
                else:
                    set_[i] += 1
                if set_[i] > max_:
                    max_ = set_[i]
                    ret = i
        return ret
        
```