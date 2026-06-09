### 代码

```python3
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        Asplit=A.split()
        Bsplit=B.split()
        output=[]
        for word in Asplit:
            if word not in Bsplit and Asplit.count(word)==1:
                output.append(word)
        for word in Bsplit:
            if word not in Asplit and Bsplit.count(word)==1:
                output.append(word)
        return output
```