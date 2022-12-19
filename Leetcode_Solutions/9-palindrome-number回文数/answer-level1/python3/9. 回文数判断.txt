```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        # 不转换成字符串
        # 如果x<0，则肯定不回文
        if x < 0:
            return False
        # 将数字分为前后两段，挨个比较后面的与前面的数字
        # 如果有不相等的，直接返回False；
        # 如果比较结束没有跳出，则是回文的，返回True
        length = len(str(x))
        reverse_length = (length + 1) // 2
        tmp = length - 1
        while reverse_length > 0:
            last = x % 10
            first = x // (10**tmp)
            if last != first:
                return False
            x = x // 10
            x = x % (10**(tmp-1))
            tmp -= 2
            reverse_length -= 1
        return True
```
