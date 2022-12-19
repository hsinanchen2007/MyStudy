### 解题思路
怎么说没有什么思维可言，就是要啥给啥，
不区分大小写那就全调成大写，忽略字符那就把字符和数字都输入一个字符串里判断是否在里面，
然后抽出来一个纯净的目标串，再把他转置比较即可

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        tmp = "QWERTYUIOPASDFGHJKLZXCVBNM1234567890"
        s = s.upper()
        ans = ""
        for i in range(len(s)):
            if s[i] in tmp:
                ans += s[i]
        ans1 = ans[::-1]
        if ans1 == ans:
            return True
        else:return False
```