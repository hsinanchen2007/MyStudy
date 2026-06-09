### 解题思路
只要元素出现的次数大于数组长度的一半就跳出循环

### 代码

```python
class Solution(object):
    def majorityElement(self, nums): 
        s = set(nums)
        for num in s:
            if nums.count(num) > len(nums)/2:
                return num
                break
```