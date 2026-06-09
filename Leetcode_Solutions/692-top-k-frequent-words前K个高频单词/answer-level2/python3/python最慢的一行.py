class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        return list(sorted(list(set(words)),key=lambda x:(-words.count(x),x), reverse=False))[:k] 