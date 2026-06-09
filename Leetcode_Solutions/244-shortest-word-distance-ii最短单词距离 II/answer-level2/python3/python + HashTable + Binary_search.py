```python
import bisect
class WordDistance:
    def __init__(self, words: List[str]):
        self.hash_table = collections.defaultdict(list)
        for i, word in enumerate(words):
            self.hash_table[word].append(i)


    def shortest(self, word1: str, word2: str) -> int:
        res = float('inf')
        binary_arr = self.hash_table[word2]
        for val in self.hash_table[word1]:
            index2 = bisect.bisect(binary_arr, val)
            left = max(0, index2 - 1)
            right = min(len(binary_arr) - 1, index2)
            res = min(res, abs(val - binary_arr[left]), abs(val - binary_arr[right]))
        return res


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(words)
# param_1 = obj.shortest(word1,word2)
```