## 四行代码解决，执行时间48ms超过84%提交者

```python []
class Solution:
    def search(self, nums, target: int) -> int:
        if target in nums:
            return nums.index(target)
        else:
            return -1
```
胜在了Python内部代码的优化，通过此题也加深了对 Python内置方法的理解，`in` 使用的就是二分查找法
