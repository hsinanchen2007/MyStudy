```
class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        list1 = a.split('+')
        list2 = b.split('+')
        a1 = int(list1[0]) * int(list2[0])
        a2 = int(list1[0]) * int(list2[1].rstrip('i'))
        a3 = int(list1[1].rstrip('i')) * int(list2[0])
        a4 = int(list1[1].rstrip('i')) * int(list2[1].rstrip('i')) * (-1)
        num1 = a1 + a4
        num2 = a2 + a3
        str1 = str(num1) + '+' +str(num2) + 'i'
        return(str1)
```
