```
class Solution:
    def toGoatLatin(self, S: str) -> str:
        li = S.split(' ')
        n = len(li)
        newList = []
        for i in range(n):
            if li[i][0] in 'aeiouAEIOU':
                newList.append(li[i] + 'ma' + 'a'*(i+1))
            else:
                newList.append(li[i][1:] + li[i][0] +'ma' + 'a'*(i+1))
        print(newList)
        return ' '.join(newList)
```
