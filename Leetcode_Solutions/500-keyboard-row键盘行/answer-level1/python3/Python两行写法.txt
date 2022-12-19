    def findWords(self, words: List[str]) -> List[str]:
        l = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm']
        return [ word for word in words if any(all(ch in row for ch in word.lower()) for row in l) ]

执行用时 :40 ms, 在所有 Python3 提交中击败了97.49%的用户
内存消耗 :13 MB, 在所有 Python3 提交中击败了94.92%的用户