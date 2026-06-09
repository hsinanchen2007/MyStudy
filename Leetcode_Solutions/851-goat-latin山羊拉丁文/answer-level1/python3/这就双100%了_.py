
```python3
class Solution:
    def toGoatLatin(self, S: str) -> str:
        lists = S.split()
        n = 1
        news = []
        yuanyin = ['a','e','i','o','u','A','E','I','O','U']
        for i in lists:
            if i[0] in yuanyin:
                new = i + 'ma' + 'a'*(n)
                news.append(new)
                n+= 1
            else:
                new = i[1:] + i[0] + 'ma' + 'a'*(n)
                news.append(new)
                n += 1
        return ' '.join(news)
```