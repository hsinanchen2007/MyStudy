Python3中对数组的操作有个index()函数，这个函数能够返回目标值在数组中的位置，不过数组中不存在目标值时会报错，可以来个异常处理。
```python []
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        try:
            nums.index(target)
            return True
        except:
            return False
```
