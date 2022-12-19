### 1. 求交集
```
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        l1 = 'qwertyuiopQWERTYUIOP'
        l2 = 'asdfghjklASDFGHJKL'
        l3 = 'zxcvbnmZXCVBNM'
        l1,l2,l3 = set(l1),set(l2),set(l3)
        final = []
        for i in range(len(words)):
            s = set(words[i])
            if s&l1 == s or s&l2==s or s&l3==s:
                final.append(words[i])
        return final
```
### 2.从评论看到的，我觉得比上面好
```
class Solution(object):
    def findWords(self, words):
        set1 = set('qwertyuiop')
        set2 = set('asdfghjkl')
        set3 = set('zxcvbnm')
        res = []
        for i in words:
            x = i.lower()
            setx = set(x)
            if setx<=set1 or setx<=set2 or setx<=set3:
                res.append(i)
        return res
```
