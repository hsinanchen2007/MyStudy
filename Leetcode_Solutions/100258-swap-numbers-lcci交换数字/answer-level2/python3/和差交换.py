### 解题思路
1、求得两数之和
2、第一个数 = 和 - 第二个数
3、第二个数 = 和 - 新的第一个数

不能用中间变量，所以需要用“第一个数”来存和，在用“第一个数”来求差值

### 代码

```python
class Solution(object):
    def swapNumbers(self, numbers):
        """
        :type numbers: List[int]
        :rtype: List[int]
        """
        numbers[0] = numbers[0] + numbers[1]
        numbers[1] = numbers[0] - numbers[1]
        numbers[0] = numbers[0] - numbers[1]
        return numbers 
```