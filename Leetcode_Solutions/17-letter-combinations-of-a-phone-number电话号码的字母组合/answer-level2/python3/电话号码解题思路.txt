### 解题思路
每次在当前获取到的字符串后面添加下个数字对应字母的值
如此进行循环即可

### 代码

```python3
from typing import List
import copy

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits=="":
            return []
        str2 = ['a', 'b', 'c']
        str3 = ['d', 'e', 'f']
        str4 = ['g', 'h', 'i']
        str5 = ['j', 'k', 'l']
        str6 = ['m', 'n', 'o']
        str7 = ['p', 'q', 'r', 's']
        str8 = ['t', 'u', 'v']
        str9 = ['w', 'x', 'y','z']
        tmpstr:List[str]=[""]
        def appendlist(self,L1:List[str],L2:List[str])->List[str]:
            retList:List=[]
            for i in range(0, len(L1)):
                for j in range(0, len(L2)):
                    retList.append(L1[i]+L2[j])
            return retList
        for i in range(digits.__len__()):
            if digits[i]=="2":
                #print(str2)
                tmpstr=copy.deepcopy(appendlist(self,tmpstr,str2))
                #print(tmpstr)
            elif digits[i]=="3":
                tmpstr=appendlist(self,tmpstr,str3)
            elif digits[i] == "4":
                tmpstr=appendlist(self,tmpstr,str4)
            elif digits[i] == '5':
                tmpstr=appendlist(self,tmpstr,str5)
            elif digits[i] == '6':
                tmpstr=appendlist(self,tmpstr,str6)
            elif digits[i]=='7':
                tmpstr=appendlist(self,tmpstr,str7)
            elif digits[i] == '8':
                tmpstr=appendlist(self,tmpstr,str8)
            elif digits[i] == '9':
                tmpstr=appendlist(self,tmpstr,str9)
            else:
                return False
            i=i+1
        return tmpstr
```