```
class Solution(object):
    def removeDuplicates(self, S):
        """
        :type S: str
        :rtype: str
        """
        #方法一遍历寻找
        i = 0
        while i < len(S)-1 :
            #print(i)
            j = i+1
            if S[i] == S[j]:
                #print(S[i],S[i])
                S = S.replace(S[i]+S[j],'')
                #print(temp)
                i = 0
            else: 
                i += 1
            #print(S)
        return S

        #方法二栈
        result = [0]
        for i in S:
            if i == result[-1]:
                result.pop()
            else:
                result.append(i)
        return ''.join(result[1:])
```
