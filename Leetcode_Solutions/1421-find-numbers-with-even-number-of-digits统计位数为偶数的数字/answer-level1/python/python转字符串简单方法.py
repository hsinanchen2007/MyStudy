执行用时 :40 ms, 在所有 Python 提交中击败了83.65%的用户
内存消耗 :11.8 MB, 在所有 Python 提交中击败了38.93%的用户

### 代码

```python
class Solution(object):
    def findNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        c=0
        for i in nums:
            if len(str(i))%2==0:
                c+=1
        return c
```
谁能帮我把这段改成一行啊？不太会