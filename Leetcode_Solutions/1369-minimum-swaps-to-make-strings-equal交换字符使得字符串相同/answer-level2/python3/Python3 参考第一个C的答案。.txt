class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        if(len(s1) != len(s2)):
            return -1
        cnt1 = 0
        cnt2 = 0
        for i in range(len(s1)):
            if (s1[i] != s2[i]):
                if(s1[i]=='x'):
                    cnt1 += 1
                else:
                    cnt2 += 1
        
        n=cnt1%2
        m=cnt2%2
        if (n+m == 1):
            return -1
        elif(n==0 and m ==0):
            count = cnt1/2 + cnt2/2
        elif(n==1 and m == 1):
            count = (cnt1/2 + cnt2/2) +1
        return int(count)