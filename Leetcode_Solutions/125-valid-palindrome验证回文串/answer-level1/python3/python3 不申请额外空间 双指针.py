### 解题思路
双指针

### 解法一

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        strAndNum = 'abcdefghijklmnopqrstuvwxyz0123456789'
        p1 = 0
        p2 = len(s) - 1
        while p1 < p2:
            # 第1点注意：先判断越界
            while p1 < len(s) and s[p1] not in strAndNum:
                p1 += 1
            while p2 > -1 and s[p2] not in strAndNum:
                p2 -= 1
            # 第2点注意：第一次漏了等于号，这句话很关键
            # = 号解决除了特殊符号回文串是奇数的情况
            if p1 <= p2:
                if s[p1].upper() == s[p2].upper():
                    p1 += 1
                    p2 -= 1
                else:
                    return False
            else:
                # 没有数字字母的情况，如",.,.,."
                # ",1,2,"的情况
                return True
        # 有数字字母的回文
        return True


```