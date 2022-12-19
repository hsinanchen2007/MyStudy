### 解题思路
o判断奇偶类型，分情况处理

### 代码

```python3
class Solution():
    def numberOfSteps (self, num):
        times = 0 
        while num != 0:
            if (num % 2) == 0:
                num = num / 2
            else:
                num = num - 1
            times += 1
        return times

```