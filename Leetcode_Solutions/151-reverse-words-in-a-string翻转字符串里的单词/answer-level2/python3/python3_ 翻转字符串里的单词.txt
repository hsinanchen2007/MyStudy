```python
def reverseWords(s):
    s = [_s for _s in s.strip().split(' ') if _s.strip()]
    return ' '.join(list(reversed(s)))

print(reverseWords("    the    daf    "))
print(reverseWords("the sky is blue"))
print(reverseWords("  hello world!  "))
print(reverseWords("a good   example"))
```