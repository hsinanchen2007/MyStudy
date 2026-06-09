```
def strStr(haystack, needle):
    if not needle:
        return 0
    length = len(needle)
    length1 = len(haystack)
    if length1 > length:
        return -1
    for i in range(0, length1-length+1):
        if haystack[i:i + length] == needle:
            return i
        if i == length1-length and haystack[i:i + length] != needle:
            return -1

```
