```
class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        result = []
        temp = []
        num = 0
        for i in arr2:
            for j in arr1:
                if i == j:
                    result.append(j)
                
                if num == 0 and j not in arr2:
                    temp.append(j)
            num = 1
        print(temp)
        result += sorted(temp)
        return result
```
