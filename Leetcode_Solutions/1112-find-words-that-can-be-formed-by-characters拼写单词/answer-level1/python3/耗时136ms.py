```
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        zidian1 = {}
        set1 = set(chars)
        flg = "tr"
        num1 = 0
        for i in set1:
            zidian1[i] = chars.count(i)
        for j in words:
            flg = "tr"
            set2 = set(j)
            for k in set2:
                if k not in zidian1:
                    flg = "fl"
                    break
                elif j.count(k) > zidian1[k]:
                    flg = "fl"
                    break
            if  flg == "tr":
                num1 += len(j)
        return(num1)
```
