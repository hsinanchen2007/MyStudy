```python
class Solution:

    @staticmethod
    def isHappy(num):
        temp_dict = dict()
        sum = num
        while sum != 1:
            if temp_dict.get(sum): return False
            temp_dict[sum] = 1

            l = list(str(sum))
            sum = 0
            for num in l:
                sum += int(num) * int(num)

        return True
```
