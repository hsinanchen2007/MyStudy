### 解题思路
用ASCII码判断大小写，设置符合题意的3个判断条件

### 代码

```python3
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        dic=[]
        for i in word:
            word_asc=ord(i)
            if word_asc<97:
                dic.append(1)
            elif word_asc>=97:
                dic.append(0)
        if len(dic)==sum(dic):
            return True
        elif sum(dic)==0:
            return True
        elif sum(dic)==1 and dic[0]==1:
            return True
        else:
            return False       


```