### 解题思路
简单做法，只需要先判断 num>1, 然后依次去除 num 为 2,3,5 的因子即可。

似乎不用对 num<=0 进行判断，下部分的代码也能 work.
但是，预先判断可能更快。

另外 num == 1, 也可以不用拿出来额外判断，下部分的代码也对。

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if num <= 0:
            return False
        if num == 1:
            return True   
        # 看了下他人的解法，似乎可以不用对 num 是否为负数判断，下面的代码也能工作。
        while num%2 == 0:
            num = num//2
        while num%3 == 0:
            num = num//3
        while num%5 == 0:
            num = num//5
        if num == 1:
            return True
        else:
            return False
        
            
```