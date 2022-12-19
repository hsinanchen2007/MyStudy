```
class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:

        w,a=0,0
        num=0
        while w<len(word) and a<len(abbr):
            if word[w]==abbr[a]:
                w+=1
                a+=1
            elif not word[w]==abbr[a] and abbr[a].isalpha():
                return False
            elif abbr[a]=="0":  #数字打头不为0
                return False
            else:
                while a<len(abbr) and abbr[a].isdigit():
                    num=num*10+int(abbr[a])
                    a+=1
                w+=num
                num=0   #记得归零
        return w==len(word) and a==len(abbr)    #保证到尾，没有剩余

```
