```python
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        for w, f in collections.Counter(re.findall(r'\w+', paragraph.lower())).most_common():
            if w not in banned:
                return w
```