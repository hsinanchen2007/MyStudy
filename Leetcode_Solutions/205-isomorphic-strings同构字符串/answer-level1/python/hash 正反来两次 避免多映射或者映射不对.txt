```
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        str_dic={}
        j=0
        for i in s:
            if i not in str_dic:
                str_dic[i]=t[j]
                j+=1
            elif str_dic[i]==t[j]:
                j+=1
            elif str_dic[i]!=t[j]:
                return False
        str_dic2={}
        j=0
        for i in t:
            if i not in str_dic2:
                str_dic2[i]=s[j]
                j+=1
            elif str_dic2[i]==s[j]:
                j+=1
            elif str_dic2[i]!=s[j]:
                return False
        return True
```
