利用字典存储，减少查重时间
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = len(s)
        if(length <= 1):
            return length
        #创建字典，记录上次字母出现的位置
        temp = dict.fromkeys(list(set(s)),[0,0])
        #最大值
        Max = 1
        #子字符串起始位置
        start = 0
        for index, each in enumerate(s):
            #判断如果该字母已出现，并且在起始位置之后出现
            if(temp[each][0] != 0 and temp[each][1] >= start):
                #计算最大值
                Max = max(Max, index-start)
                #修改起始位置，为上一个出现位置的后一个
                start = temp[each][1] + 1  
            temp[each] = [1, index]
        return max(Max, length-start)
```
