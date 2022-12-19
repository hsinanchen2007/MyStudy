思路和上一题基本一样，
不过9和4放前边，先筛掉

```python []
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        num_l = [900, 1000, 400, 500, 90, 100, 40, 50, 9, 10, 4, 5, 1]
        str_l = ['CM', 'M', 'CD', 'D', 'XC', 'C', 'XL', 
                'L', 'IX', 'X', 'IV', 'V', 'I']
        t_num = 0
        res = ''
        for i in range(len(str_l)):
            while str_l[i] in s:
                t_num += num_l[i]
                s = s.replace(str_l[i], '', 1)
        return t_num
```

