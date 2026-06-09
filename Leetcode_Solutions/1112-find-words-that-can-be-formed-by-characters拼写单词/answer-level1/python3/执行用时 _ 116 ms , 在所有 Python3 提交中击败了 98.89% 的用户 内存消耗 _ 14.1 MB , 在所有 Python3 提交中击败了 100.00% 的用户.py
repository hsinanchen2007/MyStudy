
```python []
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        result = 0
        dic = {}
        for i in chars:
            dic[i] = chars.count(i)

        for i in words:
            for j in range(len(i)):
                if i[j] in dic.keys() and i.count(i[j]) <= dic.get(i[j]):
                    if j == len(i) - 1:
                        result += len(i)
                else:
                    break
        return result
```

