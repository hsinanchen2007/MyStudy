### 数学上的解释
* 33就是3.3333333...
* 3就是3.30303030...
* 34就是3.4343434...

### 小技巧
* 这里用字符串直接比较效果是一样的，其实就是字典序

### 代码

```python3
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        nums = [str(i) for i in nums]
        nums.sort(key=lambda x: x*3)
        return ''.join(nums)
```