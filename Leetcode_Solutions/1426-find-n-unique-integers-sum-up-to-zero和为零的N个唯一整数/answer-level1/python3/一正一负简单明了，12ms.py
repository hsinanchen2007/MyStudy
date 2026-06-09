### 解题思路
此处撰写解题思路
n为偶数的话，则为  正负n/2
n为奇数的话，则在  正负n/2 基础上多个0
### 代码

```python
class Solution(object):
    def sumZero(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        if n <= 1:
            return [0]
        a = []
        if n % 2 != 0:
            a = [0]
        a.extend([i for i in range(1, n // 2 + 1)])
        a.extend([-i for i in range(1, n // 2 + 1)])

        return a

```