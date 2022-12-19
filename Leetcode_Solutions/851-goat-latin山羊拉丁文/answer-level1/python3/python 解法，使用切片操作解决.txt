```
class Solution:
    def toGoatLatin(self, S: str) -> str:
        vowel = ['a','e','i','o','u','A','E','I','O','U']         # 元音字母
        S = S.split()
        res = []
        for i, s in enumerate(S):
            if s[0] in vowel:
                word = s + 'ma' + ('a'*(i+1))
            else:
                word = s[1:] + s[0] + 'ma' + ('a'*(i+1))
            res.append(word)
        return ' '.join(res)
```
