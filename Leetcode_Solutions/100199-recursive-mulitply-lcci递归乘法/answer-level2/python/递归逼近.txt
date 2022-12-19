### 解题思路
先预处理A和B，保证A>=B，每次递归逼近到最接近B但小于B的2的整数次方处（记为m），然后令B = B - m，进行下一次递归。
![image.png](https://pic.leetcode-cn.com/9abbb50bdc9a1f7ef1dca76e971d7e06a38630ab037997a5e064f00d6bcb7974-image.png)

### 代码

```python
class Solution(object):
    def multiply(self, A, B):
        """
        :type A: int
        :type B: int
        :rtype: int
        """
        def help(A, B):
            if B == 0: return 0
            if B == 1: return A
            multi, count = A, 1
            while count <= B:
                if B - count < count + count:
                    B -= count
                    break
                count += count
                multi += multi
            return multi + help(A, B)
        A, B = max(A, B), min(A, B)
        return help(A, B)
```