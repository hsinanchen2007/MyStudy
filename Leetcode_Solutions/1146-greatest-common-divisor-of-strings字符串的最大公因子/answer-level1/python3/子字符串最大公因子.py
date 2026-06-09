### 解题思路
先算出两字符串所有公约数，然后从最大公约数开始轮循，看子字符串是否是最大公因子

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        str1,str2 = sorted([str1,str2],key=lambda x:len(x))        
        if len(set(list(str1))^set(list(str2)))!=0:
            return ""
        count = []
        l1 = len(str1)
        l2 = len(str2)
        for i in range(len(str1),0,-1):
            if len(str1)%i==0 and len(str2)%i==0:
                count.append(i)
        for i in count:
            if str1[:i]*int(l1/i)==str1 and str1[:i]*int(l2/i)==str2:
                return str1[:i]
                



```