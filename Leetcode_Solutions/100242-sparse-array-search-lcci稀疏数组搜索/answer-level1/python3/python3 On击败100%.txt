class Solution:
    def findString(self, words: List[str], s: str) -> int:
        res = [i for i,v in enumerate(words) if v == s]
        return res[0] if res else -1