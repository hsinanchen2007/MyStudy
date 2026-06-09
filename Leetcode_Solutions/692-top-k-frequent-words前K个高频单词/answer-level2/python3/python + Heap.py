```python
class Word:
    def __init__(self, freq, word):
        self.freq = freq
        self.word = word

    def __lt__(self, other):
        if self.freq == other.freq:
            return self.word > other.word
        return self.freq < other.freq


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        # logK => heap
        # minimum heap
        heap = []
        frequence_dic = collections.Counter(words)
        #O(nlogk)
        for key, fre in frequence_dic.items():
            heapq.heappush(heap, Word(fre, key))
            if len(heap) > k:
                heapq.heappop(heap)
           
        #O(klogk)
        res = []
        for i in range(k):
            res.append((heapq.heappop(heap)).word)
        return res[::-1]

```