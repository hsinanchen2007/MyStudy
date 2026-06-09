# 成绩（2019.05.17）

执行用时 : 52 ms, 在Verifying an Alien Dictionary的Python3提交中击败了90.80% 的用户

内存消耗 : 13.1 MB, 在Verifying an Alien Dictionary的Python3提交中击败了85.51% 的用户

# 思路

解码和编码，将**外星语言**翻译成英语，然后用python的sorted函数特性，也就是对字符串按字典顺序排序。然后再翻译回外星语，对比前后是否有区别即可。

像不像反复翻译企图躲避论文查重的你→_→


```python
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        encode, decode, alphabet, trans = {}, {}, "abcdefghijklmnopqrstuvwxyz", []
        for i, char in enumerate(order):
            decode[char] = alphabet[i] # alien to en
            encode[alphabet[i]] = char # en to alien
        
        for i, word in enumerate(words):
            word = list(word)
            word = "".join([decode[char] for char in word])
            trans.append(word)
        trans = sorted(trans)
        
        for i, word in enumerate(trans):
            word = list(word)
            word = "".join([encode[char] for char in word])
            trans[i] = word
        return trans == words
```

