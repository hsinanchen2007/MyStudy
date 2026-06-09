### 解题思路
通过迭代将元素添加到哈希表中，同时比较target-该元素是否已经存在与哈希表中，如果存在，直接返回答案。如果不存在，赋值该元素的下标，继续添加后面的元素到哈希表中并比较。

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap={}
        for i,num in enumerate(nums):
            #if hashmap.get(target - num) is not None:
            #    return [hashmap.get(target - num),i]
            #hashmap[num] = i

            if target - num in hashmap:
                return [hashmap[target - num],i]
            hashmap[num] = i
```