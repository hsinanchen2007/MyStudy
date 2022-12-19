class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0 : return('false')
        elif x==0: return('true')
        elif x>0:
            s = str(x)
            lens =len(s)
            for i in range(lens//2):
                if s[i]!=s[lens-1-i]:
                    return'false'
                    break
                else:
                    while (i==(lens//2)-1) :
                        return 'true'
