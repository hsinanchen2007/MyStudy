![image.png](https://pic.leetcode-cn.com/f836259ca60b558bde05dfc5a11a9ac87dfa3c8276a37f3b20a6d45bdb18cff9-image.png)


```
class Solution:
    def validIPAddress(self, IP: str) -> str:
        p=IP.split('.')
        if len(p)==4:
            for i in range(4):
                m=len(p[i])
                if m>3 or m==0:
                    return 'Neither'        #位数不对
                if m>1:     
                    if not('1'<=p[i][0]<='9'):
                        return 'Neither'        #首位有其他值
                for j in range(m):
                    if not('0'<=p[i][j]<='9'):
                        return 'Neither'        #有非数字
                if int(p[i])>255:
                    return 'Neither'    #大于255
            return 'IPv4'

        p=IP.split(':')
        if len(p)==8:
            for i in range(8):
                m=len(p[i])
                if m>4 or m==0:
                    return 'Neither'        #位数不对
                for j in range(m):
                    if not('0'<=p[i][j]<='9' or 'a'<=p[i][j]<='f' or 'A'<=p[i][j]<='F'):
                        return 'Neither'        #有非数字
            return 'IPv6'

        return 'Neither'
```
