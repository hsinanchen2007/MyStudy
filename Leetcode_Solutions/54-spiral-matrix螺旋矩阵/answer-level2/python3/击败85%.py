```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        list1,list2,list3 = [],[],[]
        n1 = 0
        while [] not in matrix:
            n1 = len(matrix)
            if n1 == 1:
                list1.extend(matrix.pop(0))
            elif n1 == 2:
                list1.extend(matrix.pop(0))
                list2 = matrix.pop(0)
                list2.reverse()
                list1.extend(list2)
            elif n1 > 2:
                list1.extend(matrix.pop(0))
                list2 = matrix.pop(-1)
                list2.reverse()
                for i in matrix:
                    list1.append(i.pop(-1))
                list1.extend(list2)
                if [] in matrix:
                    break
                list3 = []
                for j in matrix:
                    list3.append(j.pop(0))
                list3.reverse()
                list1.extend(list3)
            else:
                break
        return(list1)

```
