### 解题思路
1. 利用字典模拟哈希表
2. 双指针

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # hashmap = dict()

        # for i, j in enumerate(numbers):
        #     hashmap[j] = i
        # for i, j in enumerate(numbers):
        #     last = hashmap.get(target - j)
        #     if last and i != last:
        #         return [i+1, last+1]

        i = 0
        j = len(numbers)-1
        while i < j:
            if numbers[i] + numbers[j] == target:
                return [i+1, j+1]
            elif  numbers[i] + numbers[j] > target:
                j -= 1
            else:
                i += 1
```