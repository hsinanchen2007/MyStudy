
```
class Solution:
    def findNthDigit(self, n: int) -> int:
        #慢慢来，一个一个来
        count = 0
        #一位数9个，两位数90个，...
        i = 1
        while True:
            count += i * (9 * 10 ** (i-1))
            if count >= n:
                break
            i += 1
        #我们要找的那个数在是i位数
        rest = n - (count - i * (9 * 10 ** (i-1)))
        cur_num = 10 ** (i-1) - 1 + (rest // i)
        rest = rest % i
        if rest == 0:
            str_ = str(cur_num)
            res = str_[-1]
            res = int(res)
        else:
            str_ = str(cur_num + 1)
            res = str_[rest - 1]
            res = int(res)
        return res
```

        


                
            
            
