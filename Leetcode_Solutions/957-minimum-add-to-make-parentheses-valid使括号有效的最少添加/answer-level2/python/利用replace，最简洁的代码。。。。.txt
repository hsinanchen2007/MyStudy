class Solution(object):
    def minAddToMakeValid(self, S:str):
        prelength=-1
        while prelength!=len(S):
            prelength=len(S)
            S=S.replace('()','')
        return len(S)