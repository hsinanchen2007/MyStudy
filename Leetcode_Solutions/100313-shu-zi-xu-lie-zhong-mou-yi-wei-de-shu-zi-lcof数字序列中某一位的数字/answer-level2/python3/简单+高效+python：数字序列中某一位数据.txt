### 解题思路
10以内返回 原值

10 <= n <190 10~99的数   (n-10) // 2 表示为 10~99中的第几个数（10为第0个，11为第1个）
                        (n-10) % 2  表示为那位数的第几个数字（0表示最高位）
                        比如： 12   表示为10~99中的第1个数，及11
                                    余数为0，则为11的第一个数1

### 代码

```python3
class Solution:
    def findNthDigit(self, n: int) -> int:
        max_i = 1    ## 记录数字位数
        temp_n = n   
        max_n = 10    
        if temp_n < 10:
            return temp_n
        while temp_n >= max_n:   ## 当>10，则找表示数字的位数
            max_i += 1           
            temp_n -= max_n
            max_n = max_i * 9 * 10 ** (max_i - 1)
        num_num = temp_n // max_i
        num_i = temp_n % max_i
        num_end = num_num + 10 ** (max_i - 1)
        num_end_st = str(num_end)
        return int(num_end_st[num_i])


```