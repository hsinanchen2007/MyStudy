```
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        def toList(a):
            dict={}
            for i in range(0,len(a)):
                if a[i] in dict:            #如果字母已经出现过，continue
                    continue
                else:
                    dict[a[i]]=i
            s=[]
            for i in range(0,len(a)):       #遍历字符串，通过字典转换为数组
                s.append(dict[a[i]])
            return s
        

        if toList(s)==toList(t):
            return True
        else:
            return False
        
```
