Python3直观暴力解法：
```python
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ip = []

        for i in range(1, 4):
            s1 = s[0:i]
            if self.valid(s1):
                for j in range(i + 1, i + 4):
                    s2 = s[i:j]
                    if self.valid(s2):
                        for k in range(j + 1, j + 4):
                            s3 = s[j:k]
                            if self.valid(s3):
                                s4 = s[k:]
                                if self.valid(s4):
                                    ip.append("%s.%s.%s.%s" % (s1, s2, s3, s4))
        return ip
    
    def valid(self, segment):
        if segment:
            return int(segment) <= 255 if segment[0] != '0' else len(segment) == 1
        else:
            return False
```