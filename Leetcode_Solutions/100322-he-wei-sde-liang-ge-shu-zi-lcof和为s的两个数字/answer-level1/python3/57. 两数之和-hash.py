### 解题思路
和之前返回数组下标思路一样，但可以更简单。
没必要先把所有下标、数字放进hashmap，因为这样需要遍历两遍nums。
因为不要求顺序，可以遇见一个数，找得到匹配就返回；找不到就加入hashmap。

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if not target or len(nums) == 1:
            return []
        if nums[-2]+nums[-1] < target or nums[0]+nums[1] > target:
            return []
        map = {}

        for num in nums:
            if (target-num) in map:
                return [num, target-num]
            else:
                map[num] = 0
        return []
```