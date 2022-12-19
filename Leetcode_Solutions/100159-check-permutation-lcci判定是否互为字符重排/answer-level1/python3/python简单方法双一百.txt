![捕获.PNG](https://pic.leetcode-cn.com/0cc5fa08b3392e6655e149c25721ac6f481170003e5cdbbfa9eb855a1cd52d00-%E6%8D%95%E8%8E%B7.PNG)

### 解题思路
挺简单的
1.如果len不同，返回0
2.新建一个列表B里存放set(s1)
3.比较s1和s2中各不同字母的数量

### 代码

```python
class Solution(object):
    def CheckPermutation(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1)!=len(s2):
            return 0
        B=set(s1)
        for i in B:
            if s1.count(i)!=s2.count(i):
                return 0
        return 1

```