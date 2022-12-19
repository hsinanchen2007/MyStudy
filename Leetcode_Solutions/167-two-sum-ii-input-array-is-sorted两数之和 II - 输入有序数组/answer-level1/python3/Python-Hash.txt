```
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        dict={}
        for i,num in enumerate(numbers):
            #dict[num] = i
            #print(dict.items())
            sub = target-num
            if sub in dict:
                return [dict[sub]+1,i+1]
            else:
                dict[num] = i
            '''
            if num in dict:
                return [dict[num],i+1]
            else:
                dict[target-num] = i+1
            '''
```
