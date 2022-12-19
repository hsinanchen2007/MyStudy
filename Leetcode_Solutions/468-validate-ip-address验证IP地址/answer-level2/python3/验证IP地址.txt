```
class Solution:
    def validIPAddress(self, IP: str) -> str:
        IPlist = IP.split('.')
        IPlen = len(IPlist)
        if IPlen == 4:
            for s in IPlist:
                if not s.isdigit():
                    return 'Neither'
                if  0 <= int(s) <= 255:
                    if str(int(s)) != s: #保证没有多余的前导0
                        return 'Neither'
                else:
                    return 'Neither'
        
            return 'IPv4'
        
        IPv6 = IP.split(':')
        IPv6len = len(IPv6)
        if IPv6len == 8:
            if "" in IPv6:
                return 'Neither'
            
            for c in IPv6:
                if len(c) > 4:
                    return 'Neither'
                for a in c:
                    if a.upper() > 'F' or (a.isdigit() == False and a.isalpha() == False):
                        return 'Neither'
            return 'IPv6'
        
        return 'Neither'
```
