### 解题思路
此处撰写解题思路
发挥出python的处理字符串极其方便的优势，通过字符串切片实现

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if x < 0:
            reverse_str = '-' + str(x)[:0:-1]
        else:
            reverse_str = str(x)[::-1]

        if -2**31 <= int(reverse_str) <= 2**31-1:
            return int(reverse_str)
        else:
            return 0


```