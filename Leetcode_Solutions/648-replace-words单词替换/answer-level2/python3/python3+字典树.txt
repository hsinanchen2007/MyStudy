### 解题思路
字典树操作

### 代码

```python3
class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        d = {}
        for word in dict:
            t = d
            for char in word:
                if char not in t:
                    t[char] = {}
                t = t[char]
            t['end'] = True
        sentence = sentence.split()
        for i in range(len(sentence)):
            t = d
            for j in range(len(sentence[i])):
                if 'end' in t:
                    sentence[i] = sentence[i][:j]
                    break
                elif sentence[i][j] not in t:
                    break
                else:
                    t = t[sentence[i][j]]
        return ' '.join(sentence)
```