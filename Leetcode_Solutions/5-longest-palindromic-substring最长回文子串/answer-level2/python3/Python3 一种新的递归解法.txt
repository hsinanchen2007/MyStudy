这道题是有很明显的动态规划性质：
  字符串S的最长回文子串只有两种可能：1、（包含S最后一个字符）即以S最后一个字符为末尾；2、等于S[:-1]的最长回文子串
# 解法1：首尾交替剔除法
每一次迭代中，都分别剔除字符串S的首字母和尾字母，然后进入递归
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        """Method 1 : 首尾剔除递归  O(2^n) 超时"""
        if s[::-1] == s:
            return s
        else:
            leftPart = self.longestPalindrome(s[:-1])
            leftPart = self.longestPalindrome(s[1:])
            if len(rightPart) >= len(leftPart):
                return rightPart
            else:
                return leftPart
```
时间复杂度很大， O(2^n)
# 解法二：对解法一的优化
```
"""Method 2 : 单尾剔除 O(n) 空间复杂度较高"""
        if s[::-1] == s:
            return s
        else:
            
            def rightPalindrome(s):
                """找以最后一个单词为末尾的最大回文数"""
                index = s.find(s[-1])
                if s[index:] == s[index:][::-1]:
                    return s[index:]
                else:
                    return rightPalindrome(s[index+1:])
                
            leftPart = self.longestPalindrome(s[:-1])    
            rightPart = rightPalindrome(s)    # 直接找以末尾字符为结尾的回文子串
            
            if len(rightPart) >= len(leftPart):
                return rightPart
            else:
                return leftPart
```
时间复杂度 O(n)
