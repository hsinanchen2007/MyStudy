class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        lst= A.split(' ')+B.split(' ')
        newlst=[]
        for i  in  lst:
            if lst.count(i)==1:
                newlst.append(i)
        return newlst