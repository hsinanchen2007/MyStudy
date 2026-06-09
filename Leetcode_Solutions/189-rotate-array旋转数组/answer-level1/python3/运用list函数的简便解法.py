### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(k):
            tmp = nums.pop()
            nums.insert(0,tmp)
```