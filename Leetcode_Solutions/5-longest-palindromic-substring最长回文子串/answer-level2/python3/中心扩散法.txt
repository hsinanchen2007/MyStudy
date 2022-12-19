中心扩散法是最容易理解的方法
从一个位置i开始判断：1、string[i-1] == string[i+1] ? yes则该最长子串为奇数长度，前后跨同样的步长继续寻找直到找到不相等的字符
                    2、string[i] == string[i+1] > yes 则为偶数长度，同样前后相同的跨步长直到不一样字符
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s)  == 0:
            return s
        save = [s[0],0]
        
        for i in range(0,len(s)-1):
            if s[i] == s[i+1]:
                go = 0
                print(s[i],s[i+1])
                while  i-go >=0 and 1+i+go < len(s):
                    if s[i-go] == s[i+1+go] :
                        go += 1
                    else :
                        #走到不相等的地方
                        break
                #走到超出字符的地方也会跳出
                length = 2*go
                
               
                if length > save[1]:
                    save[0] = s[i-go+1:i+1+go]
                    save[1] = length
            if i > 0:
                if s[i-1] == s[i+1]:
                    go = 1
                    while i-go >=0 and i+go < len(s):
                        if s[i-go] == s[i+go] :
                            go += 1
                        else :
                            break
                    length = 2*go-1
                    
                    if length > save[1]:
                        save[0] = s[i-go+1:i+go]
                        save[1] = length
        return save[0]
```
