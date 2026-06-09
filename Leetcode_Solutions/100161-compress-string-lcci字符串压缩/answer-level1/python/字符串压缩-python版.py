class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return ''
        newstr = ''
        newstr += S[0]
        totle = 1
        for i in S[1:]:
            if i == newstr[-1]:
                totle += 1
            else:
                newstr += str(totle)
                newstr += i
                totle = 1
        newstr+=str(totle)
        return newstr if len(newstr)<len(S) else S