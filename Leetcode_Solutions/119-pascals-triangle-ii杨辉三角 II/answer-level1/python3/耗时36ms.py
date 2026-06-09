```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        list1 = []
        for i in range(rowIndex+1):
            if list1 == []:
                list1.append([1])
            elif len(list1) == 1:
                list1.append([1,1])
            else:
                n1 = len(list1[i-1])
                list2 = []
                for j in range(n1):
                    if j == 0:
                        list2.append(1)
                    else:
                        list2.append(list1[i-1][j]+list1[i-1][j-1])
                list2.append(1)
                list1.append(list2)
        return(list1[-1])
```
