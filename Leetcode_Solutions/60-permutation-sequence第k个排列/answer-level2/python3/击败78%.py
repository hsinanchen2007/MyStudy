```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        str1 = ""
        list1 = []
        for i in range(1,n+1):
            list1.append(i)
        while True:
            n1 = 1
            for j in range(1,n):
                n1 *= j	
            t1 = k // n1
            t2 = k % n1
            if t2 != 0:
                str1 += str(list1.pop(t1))
                if t2 == 1:
                    for z in list1:
                        str1 += str(z)
                    return(str1)
                n -= 1
                k = t2
            else:
                str1 += str(list1.pop(t1-1))
                list1.reverse()
                for k in list1:
                    str1 += str(k)
                return(str1)
```
