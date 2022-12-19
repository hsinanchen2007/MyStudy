### 解题思路
remove方法,利用异常捕获，执行速度很快

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        try:
            while True:
                nums.remove(val)
        except:
            return len(nums)          
        
```