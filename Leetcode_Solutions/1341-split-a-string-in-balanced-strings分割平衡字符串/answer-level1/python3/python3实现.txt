```
def balancedStringSplit(self, s: str) -> int:
        #从头开始循环，遇到一个和自己不一样的开始寻找，直到匹配，然后再重新开始
        num=0
        a=0
        types=''
        for i in range(len(s)):
            if a==0:#重头开始
                a+=1
                types=s[i]#记录下头
                continue
            else:#不是重头开始
                if types==s[i]:#和头一样下一个
                    a+=1
                    continue
                else:
                    a-=1
                    if a==0:#减小为0匹配上了，num+1
                        num+=1
                    continue
        return num
```
