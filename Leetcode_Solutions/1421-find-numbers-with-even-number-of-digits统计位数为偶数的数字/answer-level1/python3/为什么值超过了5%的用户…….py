### 解题思路
嗯……我想可能因为是最简单的写法吧。。。所以各种低效

思路就是，把一个数据遍历一遍，每一个去求它的长度，如果是偶数的话加一。

限制条件没加，if判断下就可以了，加上了岂不是垫底了。

### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        L = len(nums)
        res = 0
        for i in range(L):
            if len(str(nums[i])) % 2 == 0:
                res = res + 1
        return res
```