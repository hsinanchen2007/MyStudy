
```
class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if s1.__len__()>s2.__len__():
            return False
        if s1=='':
            return True

        import collections
        s1_dic=collections.Counter(s1)
        s2_dic=collections.Counter(s2[0:s1.__len__()-1+1]) #两边都是下标

        sli_dic={}
        for key in s1_dic.keys():
            if key in s2_dic.keys():
                sli_dic[key]=s2_dic[key]
            else:
                sli_dic[key]=0
                
        if sli_dic==s1_dic:
            return True

        for i in range(s1.__len__(),s2.__len__()):
            if s2[i-s1.__len__()] in s1_dic.keys():
                sli_dic[s2[i-s1.__len__()]]-=1
            if s2[i] in s1_dic.keys():
                sli_dic[s2[i]]+=1
            if sli_dic==s1_dic:
                return True
        return False
```