### 解题思路
当num=0结束
当num为偶数，num=num/2 计数加一
当num为奇数，num=num-1 计数加一

### 代码

```python
class Solution(object):
    def numberOfSteps (self, num):
        i = 0
        if num == 0:
            return 0
        elif num % 2 == 0:
            num = num / 2
            i = 1 + self.numberOfSteps(num)
        elif num % 2 == 1:
            num = num - 1
            i = 1 + self.numberOfSteps(num)
        return i
```