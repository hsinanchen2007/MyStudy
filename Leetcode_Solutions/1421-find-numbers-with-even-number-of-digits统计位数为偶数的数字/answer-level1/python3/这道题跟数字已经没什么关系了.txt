### 解题思路
这道题的本质就是将输入的list里的所有数字看成字符串，输出则为字符串长度为偶数的字符串的个数。


### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        res = []
        for i in nums:
            if len(str(i)) % 2 ==0:
                res.append(i)
        return len(res)
```