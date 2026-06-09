### 解题思路
与官方题解2类似。加入isPalindrome()函数判断剩余的子字符串是否为回文字符串。

时间复杂度：O(n)，遍历原字符串一次，遍历子字符串两次
空间复杂度：O(1)

### 代码

```python3
class Solution:
    def validPalindrome(self, s: str) -> bool:
        left=0
        right=len(s)-1
        while left < right:
            if s[left]==s[right]:
                left+=1
                right-=1
            else:
                return self.isPalindrome(s,left+1,right) or self.isPalindrome(s,left,right-1)
        return True

    def isPalindrome(self,s,left,right):
        while left < right:
            if s[left]==s[right]:
                left+=1
                right-=1
            else:
                return False
        return True
```