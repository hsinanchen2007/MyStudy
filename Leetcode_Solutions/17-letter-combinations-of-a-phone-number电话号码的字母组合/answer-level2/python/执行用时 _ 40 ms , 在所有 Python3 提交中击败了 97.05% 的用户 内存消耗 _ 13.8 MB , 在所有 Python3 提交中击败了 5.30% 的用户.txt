
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        self.dt={
            "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"pqrs",
            "8":"tuv",
            "9":"wxyz"
        }
        self.res=[]
        self.backtrack(digits,0,'')
        return self.res
    def backtrack(self,s,i,pre):
        if i >= len(s):
            return
        for le in self.dt[s[i]]:
            if i==len(s)-1:
                self.res.append(pre+le)
            self.backtrack(s,i+1,pre+le)