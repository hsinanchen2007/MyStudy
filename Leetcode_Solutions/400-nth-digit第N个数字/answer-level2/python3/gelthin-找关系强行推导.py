### 解题思路
考虑 n 处在哪一段，以每一段的结尾处作为标志位：

[1,9] 9*1
[10,99] 90*2
[100,999] 900*3
[1000,9999] 9000*4
...

+ 先判断 n 处在哪一段，然后 n - 前面所有段的累加值。
+ 然后考虑从当前段的第一个数开始，n 位于哪一个数，
+ 然后考虑 n 具体对应的数位。 

#### 取对应数
这里可以写为: (n-old_count+k-1)//k 如果有结余就顺延到下一个数，如果整除就还是整除对应的数。

#### 取数位
整除应该对应的是最后一个数位，若用 (n-old_count)%k 作为下标，就会导致整除对应0，对应到第一个数位，
恰好可以直接使用 (n-old_count+k-1)%k 作为下标， 整除对应 k-1, 多一个数对应 0， 多两个数对应 1

``` python3
# (n-old_count+k-1)//k 恰好代表了需要顺延的下一个数
# (n-old_count+k-1)%k 恰好对应了下标
return str(first-1 + (n-old_count+k-1)//k)[(n-old_count+k-1)%k] #下标从 0 开始
```

### 代码

```python3
class Solution:
    def findNthDigit(self, n: int) -> int:
        k = 1
        count = 9*1
        num = 9
        while count<n:
            k += 1
            num *= 10
            count += k*num
        old_count = count - k*num
        end = 10**(k-1) - 1
        # (n-old_count+k-1)//k 恰好代表了需要顺延的下一个数
        # (n-old_count+k-1)%k 恰好对应了下标
        return str(end + (n-old_count+k-1)//k)[(n-old_count+k-1)%k] #下标从 0 开始


class Solution:
    def findNthDigit(self, n: int) -> int:
        k = 1
        count = 9*1
        num = 9
        while count<n:
            k += 1
            num *= 10
            count += k*num
        old_count = count - k*num

        first = 10**(k-1)
        if (n-old_count) % k == 0:
            return str(first + (n-old_count)//k-1)[-1] 
        else:  # 有余，往前一个数
            return str(first + (n-old_count)//k)[(n-old_count)%k-1] #下标从 0 开始
```