### 解题思路
此处撰写解题思路

### 代码

```python3
class WordsFrequency:
    def __init__(self, book: List[str]):
        self.word_dict = collections.Counter(book)

    def get(self, word: str) -> int:
        return 0 if word not in self.word_dict else self.word_dict[word]




# Your WordsFrequency object will be instantiated and called as such:
# obj = WordsFrequency(book)
# param_1 = obj.get(word)
```