### 解题思路

先创建字典，最后根据字典查看，关键点在于最后三个字符的处理

### 代码

```python
class Solution(object):
    def freqAlphabets(self, s):
        """
        :type s: str
        :rtype: str
        """
        x=96
        dic={}
        for i in range(1,10):
            dic[str(i)]=chr(x+i)
        # print(dic)
        for i in range(10,27):
            dic[str(i)+'#']=chr(x+i)
        # print(dic)
        ##s="10#11#12"
        i=0
        re=''
        while i<len(s):
            #print(s[i],i)
            if (i+2)<len(s):
                if int(s[i])<3 and s[i+2]=='#':
                    x=dic.get(s[i]+s[i+1]+s[i+2])
                    re +=x
                    i +=3
                else:
                    x=dic.get(s[i])
                    re +=x
                    i +=1
            else:
                x=dic.get(s[i])
                re +=x
                i +=1
        return re


```
![1.png](https://pic.leetcode-cn.com/9f06c44c9b9211c868e1db5f4ee4466b1f984e145bc809174bad4f129a115b09-1.png)