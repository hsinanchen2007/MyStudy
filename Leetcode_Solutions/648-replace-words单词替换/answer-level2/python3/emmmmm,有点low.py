```
class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        dict = sorted(dict)
        sentence = sentence.split(" ")
        for i in range(len(sentence)):
            for j in dict:
                if sentence[i].startswith(j):
                    sentence[i] = j
                    break
        return " ".join(sentence)
```
