```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res=''
        if strs==[]:
            return res
        s=strs[0]
        for i in range(len(s)):
            for j in range(1,len(strs)):
                if len(strs[j])<=i:
                    return res
                else:
                    if s[i]==strs[j][i]:
                        continue
                    else:
                        return res
            else:
                res+=s[i]
        return res
```
