### 解题思路
本人python初学者,高中都没上过,初次接触这个刷题网站,只能偶尔完成一部分题.
对于本题,首先想到的就是python的切片反转,然后注意一下正负号,再者就是把反转回来的字符串转变为数值,防止如0012这样的现象出现,最后加一个是否溢出的判断,不求算法合理什么的,只求先能完成题的要求.

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        
        flag = 1
        if x < 0:
            flag = -1
            
        n = int(str(x * flag)[::-1]) * flag
        return n if -2 **31 < n < 2** 31 - 1 else 0
```