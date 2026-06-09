### 解题思路
简单粗暴的来的，通过切片的形式完成数字的反转。首先将整数转化成字符型方便操作，然后通过while循环去掉数字末尾的所有0，紧接着根据是否有负号进行反转。得到结果后将其转义并判断是否满足位数要求。
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        target = str(x)
        range = 2**31
        while target[-1] == 0:
            target = target[:-1]
        if target[0] != '-':
            result = target[::-1]
        else:
            result = target[0] + target[:0:-1]
        result = int(result)
        if result >= -range and result <= range-1:
            return result
        else:
            return 0
```