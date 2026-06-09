class Solution:
    def isUnique(self, astr: str) -> bool:
        return len(set(astr)) == len(astr) # set 不重复数列，处理后两者长度不一