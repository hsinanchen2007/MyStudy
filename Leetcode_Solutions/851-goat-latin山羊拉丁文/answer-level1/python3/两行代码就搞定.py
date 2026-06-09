```
class Solution(object):
    def toGoatLatin(self, S):
        l = list(enumerate(S.split(' ')))
        return ' '.join([i[1] + 'ma' + (i[0]+1) * 'a' if i[1][0].lower() in ['a', 'e', 'i', 'o', 'u'] else i[1][1:] + i[1][0] + 'ma' + (i[0]+1) * 'a' for i in l])
```
