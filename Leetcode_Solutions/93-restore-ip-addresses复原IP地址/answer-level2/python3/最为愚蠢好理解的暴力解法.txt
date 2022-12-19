class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:     
        out = []
        for a in range(1,4):
            for b in range(1,4):
                for c in range(1,4):
                    for d in range(1,4):
                        if a+b+c+d == len(s) and 0<=int(s[0:a])<=255 and 0<=int(s[a:a+b])<=255 and 0<=int(s[a+b:a+b+c])<=255 and 0<=int(s[a+b+c:a+b+c+d])<=255:
                            if (s[0]=="0" and a != 1) or (s[a] == "0" and b!=1) or (s[a+b]=="0" and c !=1) or (s[a+b+c]=="0" and d !=1): 
                                tem = ""
                            else:
                                tem = s[0:a]+"."+ s[a:a+b] +"."+s[a+b:a+b+c]+"."+s[a+b+c:a+b+c+d]
                                out.append(tem)
        return out