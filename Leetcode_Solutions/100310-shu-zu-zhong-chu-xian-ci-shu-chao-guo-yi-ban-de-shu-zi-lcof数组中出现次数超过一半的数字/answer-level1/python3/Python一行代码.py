### 解题思路
排序然后取中间元素即可

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return sorted(nums)[int(len(nums)/2)]

```