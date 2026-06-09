```
class Solution:
    def maximum69Number (self, num: int) -> int:
        str1 = str(num)
        list1 = list(str1)
        str2 = ""
        if "6" not in list1:
            return(num)
        else:
            list1.remove("6")
            list1.insert(0,"9")
            for i in list1:
                str2 += i
            return(int(str2))
```
