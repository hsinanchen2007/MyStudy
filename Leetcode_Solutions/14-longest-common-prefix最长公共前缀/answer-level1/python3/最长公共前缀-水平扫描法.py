![image.png](https://pic.leetcode-cn.com/296ed2f9af0c0e79bc42ad4d0d71b176c649e3abaf6141fedee25b34a1dbea90-image.png)


```
class Solution(object):
        
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        
        if '' in strs or strs == []: return ''
        
        common = strs[0]
        for n in range(1, len(strs)):
            temp = ''
            
            for i in range(min(len(common), len(strs[n]))):
                if common[i] == strs[n][i]:
                    temp += common[i]
                else:
                    break
                    
            common = temp

        return common
```
