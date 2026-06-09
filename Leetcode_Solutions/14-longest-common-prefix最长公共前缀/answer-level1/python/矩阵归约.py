```
代码块
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        if len(strs) == 1:
            return strs[0]
        minlen = min([len(s) for s in strs])
        if minlen ==0:
            return ""
        result = []
        import numpy as np
        firststr = np.asarray(list(strs[0][:minlen]))
        for l in range(1, len(strs)):
            result.append([firststr == np.asarray(list(strs[l][:minlen]))])
        result = np.concatenate(result, axis=0)
        result = np.prod(result, axis=0)
        num = 0
        for i in range(result.shape[0]):
            if not result[i]:
                break
            else:
                num+=1
        if num>0:
            return strs[0][:num]
        else:
            return ""
        
```




所有的字符串只遍历了两遍
我真是个鬼才
虽然慢了点， 也可能是字符串太少了
