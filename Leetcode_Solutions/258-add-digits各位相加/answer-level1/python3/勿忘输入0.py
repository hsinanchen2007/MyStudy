### 解题思路
python 利用9+1的模式来进行代码，但是需要考虑到输入为0的情况

### 代码

```python
class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num == 0:
            return 0
        return (num-1)%9+1

```