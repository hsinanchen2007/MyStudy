### 解题思路
暴力搞法：先让字符串等长，保存进位，最后去除左边的0
执行用时: 24 ms
内存消耗: 11.9 MB



### 代码

```python
class Solution(object):
    def addBinary(self, a, b):
        if int(a) == 0:
            return b
        if int(b) == 0:
            return a
        a_len, b_len = len(a), len(b)
        r_len = a_len + 1 if a_len >= b_len else b_len + 1
        a, b, carry = list(a), list(b), 0
        while len(a) < r_len:
            a.insert(0, '0')
        while len(b) < r_len:
            b.insert(0, '0')
        r_str = ['0' for i in range(r_len)]
        while r_len >= 0:
            r_len = r_len - 1
            t_sum = int(a[r_len]) + int(b[r_len])
            if t_sum == 2:
                r_str[r_len] = str(0 + carry)
                carry = 1
            else:
                it_sum = t_sum + carry
                if it_sum == 2:
                    r_str[r_len] = '0'
                    carry = 1
                else:
                    r_str[r_len] = str(it_sum)
                    carry = 0
        ret = ''.join(r_str).lstrip('0')
        return ret

```