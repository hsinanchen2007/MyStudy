### 解题思路
[@woodnote](/u/woodnote/)借鉴该思路用python完成

### 代码

```python
class Solution(object):
    def numDupDigitsAtMostN(self, N):
        """
        :type N: int
        :rtype: int
        """

        def factorial(n):
            if n == 1:
                return 1
            return n * factorial(n - 1)
        
        def A(m,n):
            return factorial(m) / factorial(m - n)

        digits = []
        N_copy = N
        while N_copy > 0:
            digits.append(int(N_copy % 10))
            N_copy //= 10
        digits = digits[::-1]
        
        count = 0
        ## case 1，高位带0
        for i in range(len(digits) - 1):
            tmp = 9 * A(9, i)
            count += tmp
        
        ## case 2，高位不带0
        used_num = []
        for i in range(len(digits)):
            if digits[i-1] in used_num[:-1]: ## 遇到重复结束循环
                break
            for j in range(int(i == 0),digits[i]):
                if j not in used_num:
                    tmp = A(9 - i, len(digits) - i - 1)
                    count += tmp
            used_num.append(digits[i])
        if len(used_num) == len(set(used_num)): ## 验证N本身是否满足
            if digits[i] not in used_num[:-1]:
                count += 1

        return N - count


```