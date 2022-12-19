### 解题思路

这一题最开始是套 huangyu 老师上课提到的习题 [189. 旋转数组](https://leetcode-cn.com/problems/rotate-array/)

结果想错了，导致了错误的代码，我的想法是遍历 s2, 找到第一个与s1[0]相同的字母，然后把这个作为起点，一直匹配下去。 但是，与 s1[0] 相同的字母可能有多个，不一定是第一个导致错误。
例如： "twowater" 和 "watertwo"  然后 匹配 twowater, tertwowa 当然无法匹配，出现 bug.

看他人题解， 把 s1翻一倍， s1+s1, 那么 s2 必然是 s1+s1 的子串。确实非常巧妙

这个想法在习题[1071. 字符串的最大公因子](https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/) 
[面试题 02.07. 链表相交](https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/)
也有应用。
 





### 代码

```python3
class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        return s1 in s2+s2
```