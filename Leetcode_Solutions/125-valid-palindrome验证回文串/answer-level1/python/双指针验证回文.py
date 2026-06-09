### 解题思路
左右指针从两端依次验证所指字符是否相同

### 代码

```python
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) < 2:
            return True

        left, right = 0, len(s)-1

        while left < right:
            # 只验证字符和数字
            if not s[left].isalnum():
                left += 1
                continue
            if not s[right].isalnum():
                right -= 1
                continue
            # 不区分大小写
            if s[left].lower() != s[right].lower():
                return False
            # 双指针左右移动判断下一个字符
            left += 1
            right -= 1
        return True










```