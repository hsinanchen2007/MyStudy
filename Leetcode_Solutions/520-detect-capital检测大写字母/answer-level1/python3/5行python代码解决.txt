class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.upper() == word or word.lower() == word:
            return True

        elif word[0].upper()+word[1:].lower() == word:
            return True
        return False

执行用时 :40 ms, 在所有 Python3 提交中击败了97.90%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了5.26%的用户