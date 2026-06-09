### 解题思路
根据k和(n-1)!的关系可以确定最高位数字，通过这种思路可以一步步确定所有位的数字。
![image.png](https://pic.leetcode-cn.com/cb483dcaa726a2437571ba74a8b15a50141b57024832e0d6a0992f3e840106ce-image.png)

### 代码

```python
import math
class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        res = ""
        refer = [str(i) for i in range(1, n+1)]
        k_modify = k - 1
        while n > 0:
            s = k_modify // math.factorial(n-1)
            k_modify %= math.factorial(n-1)
            res += refer.pop(s)
            n -= 1
        return res
```