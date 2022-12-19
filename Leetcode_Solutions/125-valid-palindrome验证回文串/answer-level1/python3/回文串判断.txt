### 解题思路
此处撰写解题思路
1、首先通过filter函数过滤掉非字母和数字的串
2、字符串长度，获取最左边和最右边的的index
3、两两比较最左和最右的字符串是否相当。直到最左指针大于最右指针
### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = list(filter(str.isalnum, s))  # 过滤掉非字母数字的字符串
        number = len(s)
        # if number/2 != 0:  # 如果长度为奇数，则不是回文
        #     return False
        left = 0
        right = number -1
        while left < right:
            if s[left].lower() != s[right].lower():
                return False
            left+=1
            right-=1
        return True
```