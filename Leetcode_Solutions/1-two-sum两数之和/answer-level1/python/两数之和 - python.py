### 解题思路
哈希表，重点是在一遍循环中找是否存在target-num1(循环值)
对于python来说巧用dict -> hashmap
dict找是否存在key三种方法：1)if key in dict ;2)dict[key]; 3)dict.get(key)。其中方法三最慢，不要用
巧用python中的enumerate -> list变dict[val] = index

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = dict()
        for ind,val in enumerate(nums):
            if (target-val) in hashmap:
                return [ind,hashmap[target-val]]
            hashmap[val] = ind
```