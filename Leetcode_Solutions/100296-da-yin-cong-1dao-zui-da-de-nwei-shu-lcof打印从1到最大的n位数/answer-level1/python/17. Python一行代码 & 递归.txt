### 解题思路
Python只需要用这一行代码就能实现。但也实现了一下递归方法。
递归方法看成是n位数字的组合，但是需要注意两点：
（1）从左边第一个非0位开始输出；
（2）要考虑0这个特殊值，否则答案会包括0 。

### 代码

```python
class Solution(object):
    def printNumbers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = []
        def get_num(s, bit, ind):
            """
            :param s -> str: s是当前生成的字符串
            :param bit -> int: bit是当前已经生成的位数
            :param ind -> int: ind是第一个非零位的下标
            """
            if bit == n:
                # 排除0
                if s[ind:] != '': 
                    res.append(int(s[ind:]))
                return 
            for i in range(10):
                if ind == bit and i != 0 or ind < bit:
                    get_num(s + str(i), bit + 1, ind)
                else:
                    get_num(s + str(i), bit + 1, ind + 1)
        get_num('', 0, 0)
        return res

    def printNumbers_2(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        return [i for i in range(1, 10 ** n)]
```