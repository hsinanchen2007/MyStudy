### 解题思路
s = s[::-1] 判断反转后与原字符串是否相同，真则直接返回
双指针法，i从左，j从右，s[i] != s[j]时有两种情况：
1.删右，判断a=s[i:j]是否为回文字符串
2.删左，判断b=s[i+1,j+1]是否为回文字符串
a or b 满足即为真，不满足即为否

注意：不要忘了s[i]=s[j]时，i,j要移位，不然无限循环报错超时。
如果i>=j就输出False


### 代码

```python
class Solution(object):
    def validPalindrome(self, s):
        if s == s[::-1]:
            return True
        i,j = 0,len(s) -1
        while i < j:
            if s[i] != s[j]:
                a = s[i:j]
                b = s[i+1:j+1]
                if a == a[::-1]:
                    return True
                if b == b[::-1]:
                    return True
                return False
            else:
                i += 1
                j -= 1
        return False
```