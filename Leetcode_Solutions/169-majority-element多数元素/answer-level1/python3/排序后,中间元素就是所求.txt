### 解题思路
此处撰写解题思路
出现次数大于数组一半,那么排序后,数组的中间位置一定是这个元素
### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        sort=sorted(nums)
        return sort[len(sort)//2]
```