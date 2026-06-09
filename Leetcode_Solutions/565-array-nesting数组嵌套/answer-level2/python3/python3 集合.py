### 解题思路
由于每个位置的数字都是不同的，某一个位置的点找下去如果出现了相同元素必然是形成一个环，因此可以保存已经出现过的点，它们不需要再被检查了

### 代码

```python3
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        #思路：先来暴力检测，每个元素作为头部进行查找
        max_ = 0
        memory = set()
        for i in range(len(nums)):
            if i in memory:
                continue
            number_set = set()
            idx = nums[i]
            number_set.add(i)
            memory.add(i)
            while True:
                number_set.add(idx)
                memory.add(idx)
                if nums[idx] in number_set:
                    break
                idx = nums[idx]
            max_ = max(max_,len(number_set))
        return max_
```