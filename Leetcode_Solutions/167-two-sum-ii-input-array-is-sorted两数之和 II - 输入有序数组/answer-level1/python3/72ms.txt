```
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n1 = len(numbers)
        result = {}
        list1 = []
        for i in range(n1):
            aa = target - numbers[i]
            if aa not in result.keys():
                result[numbers[i]] = i
                #print(result)
            else:
                list1.append(result[aa]+1)
                list1.append(i+1)
                return(list1)
        
```
