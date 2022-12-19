### 解题思路
生成两个列表分别存放大写字符和对应的数值，分索引奇数和偶数两种情况讨论，索引为奇数时，逢九就不同，索引为偶数时逢4就不同。

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        string = ['M', 'D', 'C', 'L', 'X', 'V', 'I']
        nums = [1000, 500, 100, 50, 10, 5, 1]
        n = 0; res = ''
        for i, x in enumerate(nums):
            n = num//x
            if not i%2:
                if n<4:
                    res += string[i] * n
                else:
                    res += string[i] + string[i-1]
                num = num % x
            else:
                if num - nums[i-1] + nums[i+1]>=0:
                    res += string[i+1] + string[i-1]
                    num = num - nums[i-1] + nums[i+1]
                else:
                    res += string[i] * n
                    num = num % x           
        return res
```