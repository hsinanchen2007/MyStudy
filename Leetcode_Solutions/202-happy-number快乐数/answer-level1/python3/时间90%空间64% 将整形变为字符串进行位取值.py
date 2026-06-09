### 解题思路
将整形变为字符串进行位取值

### 代码

```python
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        repeat_list = []
        while n != 1:
            repeat_list.append(n)
            s = str(n)
            sqr_sum = 0
            for str_num in s:
                int_num = int(str_num)
                sqr_sum = sqr_sum + (int_num*int_num)
            n = sqr_sum
            if n in repeat_list:
                return False
        return True

```