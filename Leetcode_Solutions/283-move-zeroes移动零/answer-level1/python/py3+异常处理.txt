### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        try:
            jici=0
            while True:
                nums.remove(0)
                jici+=1
        except ValueError:
            pass
        for i in range(jici):
            nums.append(0)
```