### 解题思路
执行用时 :172 ms, 在所有 python 提交中击败了53.80%的用户
内存消耗 :11.6 MB, 在所有 python 提交中击败了40.31%的用户
![微信图片_20191208171955.png](https://pic.leetcode-cn.com/f188d6f7e414bce89c551913c8b7e56348eb17215697e146682143e1b0ee62d4-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191208171955.png)

### 代码

```python
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1 == 0 or num2 == 0:
            return 0
        if not num1 or not num2:
            return
        if len(num1) < len(num2):
            num1, num2 = num2, num1
        len_1 = len(num1)
        len_2 = len(num2)
        num_sum = [0 for _ in range(len_1 + len_2 + 2)]
        num1 = list(num1)
        num2 = list(num2)
        num1.reverse()
        num2.reverse()
        i = 0   # num2 的下标
        while i < len(num2):
            num = int(num2[i])
            if num == 0:
                i += 1
                continue
            j = 0
            while j < len(num1):
                num_sum[i + j] += num * int(num1[j])
                while num_sum[i + j] >= 10:
                    num_sum[i + j + 1] += num_sum[i + j] // 10
                    num_sum[i + j] = num_sum[i + j] % 10
                j += 1
            i += 1
        num_sum.reverse()
        # print(num1)
        # print(num2)
        i = 0
        while i < len(num_sum)-1 and num_sum[i] == 0:
            i = i + 1
        num_sum = num_sum[i:]
        s = ''.join(str(num_sum[j]) for j in range(len(num_sum)))
        print(s)
        return s
```