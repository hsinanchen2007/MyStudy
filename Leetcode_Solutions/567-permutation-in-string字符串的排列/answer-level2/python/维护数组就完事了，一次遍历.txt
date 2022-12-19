### 解题思路
python

### 代码

```python
class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1)>len(s2):
            return False
        ss1=[0]*26
        ss2=[0]*26
        sum1=sum([ord(c) for c in s1])
        for c in s1:
            ss1[ord(c)-ord('a')]+=1
        sum2=sum([ord(s2[i]) for i in range(len(s1))])
        
        for i in range(len(s1)):
            ss2[ord(s2[i])-ord('a')]+=1
        if ss1==ss2:
            return True
        
        for i in range(len(s1),len(s2)):
            sum2=sum2-ord(s2[i-len(s1)])+ord(s2[i])
            ss2[ord(s2[i-len(s1)])-ord('a')]-=1
            ss2[ord(s2[i])-ord('a')]+=1
            if sum1==sum2:                  //和相等才做判断，减少数组比对次数
                if ss1==ss2:
                    return True
        return False
                
            
        
```