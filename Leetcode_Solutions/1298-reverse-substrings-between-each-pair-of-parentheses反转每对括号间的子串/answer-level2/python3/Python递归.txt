基本思路：  
寻找第一个左括号
以及与该左括号匹配的右括号
对两个括号中间的值进行倒切片递归
对括号左边直接返回
对括号右边进行正切片递归

```
class Solution:
    def reverseParentheses(self, s: str, left_p='(', right_p=')') -> str:   # left_p, right_p分别表示当前字符串中的左右括号，倒切片后两个值要交换
        left = 0    # left用来寻找第一个"左"括号，
        while left < len(s) and s[left] != left_p:
            left += 1
        if left == len(s):  # 没找到"左"括号直接返回
            return s
        right, target = left, 1     # right用于寻找与left匹配的"右"括号
        while right < len(s) and target:
            right += 1
            if s[right] == right_p:
                target -= 1
            if s[right] == left_p:
                target += 1
        return s[:left]+self.reverseParentheses(s[right-1:left:-1], right_p, left_p)+self.reverseParentheses(s[right+1:], left_p, right_p)
                # 返回值注释：原封不动返回"左"括号以左的值 + 倒切片"左"括号与"右"括号之间的值（注意函数参数左右括号值互换） + 原封不动返回"右"括号之后的值（注意左右括号值不换）
```
