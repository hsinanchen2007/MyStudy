### 解题思路
python3暴力求解

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        if s == None:                       #空字符串视作回文序列
            return True

        s_list = []
        for i in s.lower():                 #字符串中的字母与数字形成列表，统一小写
            if i.isalnum():
                s_list.append(i)
        
        mid = len(s_list) // 2              #list左右分开，考虑奇偶位序列
        s_left = s_list[:mid]
        if len(s_list) % 2 == 0:
            s_right = s_list[mid:]
        else:
            s_right = s_list[mid+1:]

        s_right.reverse()                   #右边翻转与左边相等即回文序列
        if s_left == s_right:
            return True
        else:
            return False
```