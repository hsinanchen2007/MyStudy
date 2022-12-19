### 代码

```python3
# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        while True:
            row = rand7()
            col = rand7()
            num = col + (row - 1) * 7
            if num <= 40:
                break
        return 1 + (num - 1) % 10 # 1-10
```