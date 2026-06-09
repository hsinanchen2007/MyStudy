### 解题思路
将6种特例和常规情形从大到小定义一个列表，而后从大到小递归相减即可。

### 执行结果
![image.png](https://pic.leetcode-cn.com/e83dc4276f70778f89edebafcfe1da8c953c197d2c454f41f88ad7d22160c711-image.png)

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        nums = [(1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'), (100, 'C'), (90, 'XC'),
                (50, 'L'), (40, 'XL'), (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')]
        ans = ''
        for n, s in nums:
            while num >= n:
                ans += s
                num -= n
        return ans
```