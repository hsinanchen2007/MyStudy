思路就是从最后一个数字开始将每个前面数字代表的字母加到前面。

chardict = {'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        re = []
        if len(digits) == 0:
            return re
        if len(digits) == 1:
            for i in chardict[digits[0]]:
                re.append(i)
        else:
            for i in chardict[digits[0]]:
                for j in self.letterCombinations(digits[1:]):
                    re.append(i+j)
        return re