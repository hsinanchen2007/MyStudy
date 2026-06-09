```python
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        import re
        min_len,max_len =(len(str1),len(str2)) if len(str1) < len(str2) else (len(str2),len(str1))
        
        for i in range(1,min_len + 1):
            if min_len%i != 0:
                continue
                
            l = min_len//i
            if max_len % l != 0:
                continue
            
            s1 = re.findall(r'.{%s}'%l, str1)
            s2 = re.findall(r'.{%s}'%l, str2)
            if s1[0]==s2[0] and len(set(s1))==1 and len(set(s2))==1:
                return str1[:l]
            
        return ""
```
