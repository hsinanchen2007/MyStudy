```
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        list1 = []
        list2 = text.split(" ")
        n1 = len(list2)
        i,j = 0,1
        while j < n1:
            if list2[i] != first:
                i += 1
                j += 1
            elif list2[i] == first:
                if list2[j] != second:
                    i += 1
                    j += 1
                else:
                    try:
                        list1.append(list2[j+1])
                        i += 2
                        j += 2
                    except IndexError:
                        return(list1)
        return(list1)
```
