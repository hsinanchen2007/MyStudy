小白写，佬勿笑
将字符串倒过来比较一遍就行
只不过
执行用时 :68 ms, 在所有 Python 提交中击败了42.25%的用户
内存消耗 :11.8 MB, 在所有 Python 提交中击败了18.54%的用户
```
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        return str(x)==str(x)[::-1]
```
