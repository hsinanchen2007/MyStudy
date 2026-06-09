### 解题思路
此处撰写解题思路

### 代码

```python3
class WordsFrequency:

    def __init__(self, book: List[str]):
        # 将单词作为键，出现的次数作为值存在字典中
        book_dict = dict()
        for word in book:
            if word not in book_dict:
                book_dict[word] = 1
            else: book_dict[word] += 1
        self.book_dict = book_dict


    def get(self, word: str) -> int:
        return self.book_dict[word] if word in self.book_dict else 0



# Your WordsFrequency object will be instantiated and called as such:
# obj = WordsFrequency(book)
# param_1 = obj.get(word)
```