### 解题思路
![image.png](https://pic.leetcode-cn.com/f4b074ae0ce239b433a1904f466893efd5a0bc5ab3ded82372d3e190d279c459-image.png)

- （1）如果多个变量均非0（包括None、False等），那么返回最后一个变量的值。如3 and 2 and 'a'的返回值为'a'；
- （2）如果多个变量中存在0值，则返回第一个0值。如1 and 'a' and 0 and None的返回值为0。

### 代码

```python
class Solution(object):
    def sumNums(self, n):
        """
        :type n: int
        :rtype: int
        """
        return n and n + self.sumNums(n-1)
```