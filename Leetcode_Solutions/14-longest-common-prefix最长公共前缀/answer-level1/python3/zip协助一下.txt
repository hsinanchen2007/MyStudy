```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        first_str = set([i[0] for i in strs if i])
        if len(first_str) != 1:
            return ""
        common = ""
        for each in zip(*strs):
            if len(set(each)) == 1:
                common+=each[0]
        return common
        
        
```