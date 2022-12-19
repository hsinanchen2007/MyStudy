### 解题思路
虽然想不到那个牛逼的快慢指针法，但这个位运算也是能符合要求的。
### 代码

```python3
class Solution:
    def findDuplicate(self, nums):
        mark=0
        for i in nums:
            if mark&1<<(i-1)==0:mark+=1<<(i-1)
            else: return i
```