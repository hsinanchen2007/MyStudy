使用数组的remove()函数，但是当要删除的元素不存在时会报错，所以可以采用异常处理。
```python3 []
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        while True:
            try:
                nums.remove(val)
            except:
                return len(nums)
```


