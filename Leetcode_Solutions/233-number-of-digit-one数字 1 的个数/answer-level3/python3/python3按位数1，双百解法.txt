### 解题思路
从右往左数1的个数，注意最小位，中间位，最高位数法不同

### 代码

```python3
class Solution:
    def countDigitOne(self, n) :
        #  思路：按位数，从低到高
        if n <= 0 :
            return 0
        if n == 1:
            return 1
        #  特殊情况列举完毕
        res = 0
        temp = n
        count = 0
        while n:
            last = n % 10

            n //= 10

            if last > 1:
                res += (n + 1) * 10**count
               
            elif last == 1:
                if count >= 1 and n == 0:  # 最大位
                    res += (temp % (10**count)) + 1
                    # 如果刚好等于1加上右边那一位的数字加1
                    #print(temp % (10**count))
                elif count >= 1:#  中间位左右都要加
                    res += n * 10 ** count + (temp % (10**count)) + 1
                else:  # 最小位
                    res += n * 10 ** count + 1
            else:
                res += n * 10**count
            print(res)
            count += 1
        #print(res)
        return res

```