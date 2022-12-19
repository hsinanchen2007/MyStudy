### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        lens = len(nums) / 2
        a = {}
        for num in nums :
            if str(num) not in a :
                a[str(num)] = 1
            else :
                a[str(num)] = a[str(num)] + 1
            if a[str(num)] > lens :
                return num
        return 0
```