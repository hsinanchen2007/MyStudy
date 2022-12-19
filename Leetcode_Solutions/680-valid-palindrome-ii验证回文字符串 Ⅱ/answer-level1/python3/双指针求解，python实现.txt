### 解题思路
python中判断回文数非常的容易，只需一条代码。【所谓的回文字符串，是指具有左右对称特点的字符串】
即：a[::-1] == a 这里a是一个字符串。
但是这题的关键在于允许删除一个字符的情况下，判断是否还是回文数。
这里可以利用双指针进行判断，当存在首尾字符不相等的时候，试着删除首部或尾部一个字符再进行判断是否是回文数。

代码参考大佬：
作者：larger5
链接：https://leetcode-cn.com/problems/valid-palindrome-ii/solution/shuang-zhi-zhen-python-by-larger5-3/

### 代码

```python
class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        p1, p2 = 0, len(s) - 1
        while p1 < p2:
            if s[p1] != s[p2]:
                # 舍弃左字符
                a = s[p1 + 1: p2 + 1]
                # 舍弃右字符
                b = s[p1:p2]
                # 判断是否为回文字符串
                return a[::-1] == a or b[::-1] == b
            p1 += 1
            p2 -= 1
        return True
```