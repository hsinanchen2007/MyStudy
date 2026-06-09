1. 若`s`长度为奇数，则各字符出现的次数必须有一个是奇数。
2. 若`s`长度为偶数，则各字符出现的次数必须全是偶数。
```
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        l = len(s)
        hashmap = {}
        odd_flag = 0
        for x in s:
            if x not in hashmap:
                hashmap[x] = 1
                odd_flag += 1
            else:
                hashmap[x] += 1
                if hashmap[x] % 2 == 0:
                    odd_flag -= 1
                else:
                    odd_flag += 1
        if l % 2 == 0:
            return odd_flag == 0
        else:
            return odd_flag == 1

```
