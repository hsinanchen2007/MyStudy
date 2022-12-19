### 解题思路
Python中for和else的一种特殊搭配用法，如果学到了请点个赞O(∩_∩)O
### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        #如果nums中存在target，返回target的索引
        if target in nums:
            return nums.index(target)
        #否则将target插入在第一个比他大的元素的索引处
        else:
            for i in range(len(nums)):
                if nums[i] > target:
                    return i
        #(重点来了，骚气写法)如果遍历完整个nums都没有比target大的数，则将target插入到末尾
            else:
                return len(nums)

```