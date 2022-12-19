### 解题思路
这里题目上说的是结果不能超过32位数，同理输入不能超过32位数1，这个要考虑。
这里要分为正数或者负数，用一个变量log来指代，并且为了统一计算，先将负数变为正数
此时我们并不知到要输进来的数的具体位数，我们就要用while循环，可以通过 while x//10来的到具体位数，并且
用一个列表来存储每一位上的数。这里要注意，/10是浮点数的除，//10才是整型数的除。
最后在已知位数的情况下，用for循环得到反转后的数
### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x<-1*(2**31) -1 or x>2**31-1:
            return 0
        result_list = []
        i = 0
        result = 0
        log = 0 
        if x < 0:
            num = (-1)*x
            log = 1
        else:
            num = x
        while num//10:
            i += 1
            result_list.append(num%10)
            num = num//10
        result_list.append(num%10)
        i+=1
        for j in range(i):
            result = result + result_list[j]*(10**(i-1-j))
        if log == 1:
            result = (-1)*result
        if result <-1*(2**31)-1 or result>2**31-1:
            return 0
        else:
            return result






        
```