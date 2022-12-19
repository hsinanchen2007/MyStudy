```
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        hashmap={}
        for ind,num in enumerate(numbers):
            hashmap[num] = ind
        for i in range(len(numbers)):
            j = hashmap.get(target-numbers[i])
            if j != None and i!=j:
                return [i+1,j+1]
```

用字典查询大大的提高了查询速度
![image.png](https://pic.leetcode-cn.com/b3287a742edc37ce6b22674fdedaee00d83daa5956cced0b852772f9c7a6ae21-image.png)
