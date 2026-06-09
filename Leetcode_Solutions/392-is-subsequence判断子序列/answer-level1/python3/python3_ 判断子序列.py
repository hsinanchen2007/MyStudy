```python
def isSubsequence(s, t):
    s = list(s)
    for _t in t:
        if not s:
            return True
        if _t == s[0]:
            s.pop(0)
    
    return not s

print(isSubsequence("abc", "ahbgdc"))
print(isSubsequence("axc", "ahbgdc"))
```