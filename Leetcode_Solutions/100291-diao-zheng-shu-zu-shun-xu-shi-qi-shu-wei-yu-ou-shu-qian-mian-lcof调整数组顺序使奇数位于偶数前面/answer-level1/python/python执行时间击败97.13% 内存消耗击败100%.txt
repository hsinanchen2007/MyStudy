### 解题思路
看了各位大神的题解我傻了，一开始我没想那么复杂。我的基本思路就是，把奇数和偶数分成两个`list`然后把两个`list`相加返回就好了，代码也比较简单。

### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        odd = []
        even = []
        for num in nums:
            if num%2==0:
                even.append(num)
            else:
                odd.append(num)
        res = odd + even
        return res
```