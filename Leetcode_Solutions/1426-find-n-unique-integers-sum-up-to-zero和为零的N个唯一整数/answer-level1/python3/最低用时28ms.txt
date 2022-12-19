```
class Solution:
    def sumZero(self, n: int) -> List[int]:
        list1 = [0]
        i = 1
        if n == 1:
            return(list1)
        else:
            for j in range(1,n,2):
                list1.append(0-i)
                list1.append(0+i)
                i += 1
        if n % 2 == 0:
            list1.remove(0)
            return(list1)
        else:
            return(list1)
```
