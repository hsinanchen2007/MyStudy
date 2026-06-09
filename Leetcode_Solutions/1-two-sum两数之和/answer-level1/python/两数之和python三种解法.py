# 1：暴力

    class Solution:
        def twoSum(self, nums, target):
            for i in range(len(nums)): 
                for j in range(i + 1, len(nums)):    
                    if (nums[i] + nums[j] == target):
                        return [i, j]
                    pass
                pass
            return None`


# 2: HASH两遍  
#HASH表中，将键值装桶中 (key value)  key是键值(要查找的值), value(index)是桶，是地址  
#hashmap[key]=value  or  hashmap[nums]=index

```
hashmap = {}
for index, num in enumerate(nums):
    hashmap[num] = index
for index, num in enumerate(nums):
    another_num = target - num
    if another_num in hashmap and hashmap[another_num] != index:
        return [index, hashmap[another_num]]
return None
```
# 3: HASH 1遍
#边找边放，相当于从后往前找

```
 hashmap = {}
        for index, num in enumerate(nums):
            another_num = target - num
            if another_num in hashmap:
                return [hashmap[another_num], index]
            hashmap[num] = index
        return None
```

