# class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        res=str.split()
        return list(map(pattern.index, pattern))==list(map(res.index,res))
        