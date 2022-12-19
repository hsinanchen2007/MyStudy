```
def string(str1,str2):
    len_str1 = len(str1)
    len_str2 = len(str2)
    str3 = str2
    if len_str1 % len_str2 == 0:
        a = len_str1 // len_str2
        str3 += (a-1)*str2
        if str1 == str3:
            print(str2)
        else:
            print(' ')
    else:
        print(' ')
```
