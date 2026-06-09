### 解题思路
先构建一个散列表，根据散列表中为1的数字

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        dict = {}
        for i in nums:
            if i in dict:
                dict[i] += 1
            else:
                dict[i] = 1
        for i in dict.items():
            if i[1] == 1:
                return i[0]
```