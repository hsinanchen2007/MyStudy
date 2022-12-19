思路:双字典分别用word和pattern作为键,求字典的交集

代码:
```python
class Solution:

    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        re = []
        re1 = []
        re2 = []
        for word in words:
            #print(word[0])
            dic1 = {}
            dic2 = {}
            i = 0
            flag1 = 1
            flag2 = 1
            while i <len(pattern):
                if str(word[i]) in dic1:
                    if dic1[str(word[i])]!=pattern[i]:
                        flag1 = 0
                else:
                    dic1[str(word[i])]=pattern[i]
                if str(pattern[i]) in dic2:
                    if dic2[str(pattern[i])]!=word[i]:
                        flag2 = 0
                else:
                    dic2[str(pattern[i])]=word[i]
                i += 1
            #print(i)
            if flag1 == 1:
                re1.append(word)
            if flag2 == 1:
                re2.append(word)
        for i in re1:
            if i in re2:
                re.append(i)
        #print(re1)
        #print(re2)
        return(re)
