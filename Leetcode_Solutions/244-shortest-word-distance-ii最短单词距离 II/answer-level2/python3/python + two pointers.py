```python
class WordDistance:
    def __init__(self, words: List[str]):
        self.hash_table = collections.defaultdict(list)
        for i, word in enumerate(words):
            self.hash_table[word].append(i)


    def shortest(self, word1: str, word2: str) -> int:
        # double pointers method
        i, j = 0, 0
        res = float('inf')
        word1_arr = self.hash_table[word1]
        word2_arr = self.hash_table[word2]
        while i < len(word1_arr) and j < len(word2_arr):
            res = min(res, abs(word1_arr[i] - word2_arr[j]))
            if word1_arr[i] < word2_arr[j]: i += 1
            else: j += 1
        return res


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(words)
# param_1 = obj.shortest(word1,word2)
```