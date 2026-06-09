```python
class ValidWordAbbr:

    def __init__(self, dictionary: List[str]):
        self.hash_table = collections.defaultdict(int)
        self.word_table = collections.defaultdict(int)
        for word in dictionary:
            if word not in self.word_table:
                self.hash_table[self.process(word)] += 1
                self.word_table[word] += 1

    def process(self, s: str) -> str:
        if len(s) <= 2: return s
        else: return s[0] + str(len(s[1: -1])) + s[-1]

    def isUnique(self, word: str) -> bool:
        
        process_word = self.process(word)
        if process_word not in self.hash_table:
            return True
        if self.hash_table[process_word] == 1 and word in self.word_table:
            return True
        return False
        


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)
```