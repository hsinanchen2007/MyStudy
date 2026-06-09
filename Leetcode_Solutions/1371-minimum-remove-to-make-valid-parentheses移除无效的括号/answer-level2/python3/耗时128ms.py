```
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        zuo = 0
        you = 0
        str1 = ""
        for i in s:
            if i == "(":
                str1 += i
                zuo += 1
            elif i == ")":
                if zuo > you:
                    str1 += i
                    you += 1
            else:
                str1 += i
        zuo_count = str1.count("(")
        you_count = str1.count(")")
        if zuo_count == you_count:
            return(str1)
        else:
            list1 = list(str1)
            list1.reverse()
            for j in range(zuo_count-you_count):
                list1.remove("(")
            str3 = ""
            list1.reverse()
            for k in list1:
                str3 += k
            return(str3)
                
```
