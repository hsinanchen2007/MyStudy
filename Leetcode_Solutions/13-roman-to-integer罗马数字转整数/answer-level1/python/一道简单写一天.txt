### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
      def romanToInt(self, s: str) -> int:
        # I=1
        # V=5
        # X=10
        # L=50
        # C=100
        # D=500
        # M=1000
        NUM=0
        m=len(s)
        n=len(s)-1
        #构造字典
        temp1 = {'I':1, 'V': 5, 'X':10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        temp2 = {'IV': 4, 'IX': 9, 'XL': 40, 'XC':90, 'CD': 400, 'CM': 900}
        i=0
        # 没有算最后一个
        if len(s)<=2:
            if s in temp2:
                NUM=temp2[s]
            else:
                for j in range (len(s)):
                    NUM=NUM+temp1[s[j]]

        else:
            while i<len(s):
                  if i<n-1:
                      if s[i:i+2] in temp2:
                         NUM1 = temp2[s[i:i + 2]]
                      # if NUM1!=None:
                         NUM=NUM+NUM1
                         i=i+2
                      else:
                          NUM1=temp1[s[i]]
                          NUM=NUM+NUM1
                          i=i+1
                  else:
                      # bbb=s[n-2:n]
                      if s[i:m] in temp2:
                         NUM2 = temp2[s[i:m]]
                      # if NUM2!=None:
                         NUM = NUM + NUM2
                         i = i + 2
                      else:
                          NUM1 =temp1[s[i]]
                          NUM = NUM + NUM1
                          i = i + 1
                          # NUM1 = temp1[s[i]]
                          # NUM = NUM + NUM1

        return NUM
```