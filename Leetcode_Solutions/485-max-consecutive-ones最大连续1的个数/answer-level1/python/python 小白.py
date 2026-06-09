```
str1 = ''
for i in nums:
    str1 += str(i)
str1_split = str1.split('0')
return len(max(str1_split, key=len))
```
