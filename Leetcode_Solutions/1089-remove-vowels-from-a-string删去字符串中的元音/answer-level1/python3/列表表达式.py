class Solution:
    def removeVowels(self, S: str) -> str:
        return ''.join([x for x in S if x not in "aeiou"])