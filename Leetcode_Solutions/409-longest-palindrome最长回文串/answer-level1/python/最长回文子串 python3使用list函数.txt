### 解题思路

效率不高，记录一下自己的思路

用list函数将字符串的每个字符都分来
一个字母同时出现两次，就去掉，cnt + 2
最后判断还有没有单独的一个字母，cnt + 1，这里用flag来标记是不是有奇数的字母

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt = 0
        flag = 0
        oper_list = list(s)

        while True:
            item = oper_list[0]
            oper_list.remove(item)
            if item in oper_list:
                oper_list.remove(item)
                cnt = cnt + 2
            else:
                flag = 1
            if len(oper_list) == 0:
                break

        if flag == 0 and len(oper_list) > 1:
            flag = 1
        cnt = cnt + flag
        return cnt
```