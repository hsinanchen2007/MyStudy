### 解题思路
1.去除标点符号 去除空格 
2.然后判断是否和反转后的字符串相等

# 执行用时 36 ms
# 内存消耗 13.4 MB

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 去除标点符号
        s_fir = s.translate(s.maketrans('','',string.punctuation))
        # 去掉空格
        s_sed = s_fir.replace(' ','')
        # 所有字母小写
        s_fin = s_sed.lower()
        return s_fin == s_fin[::-1]
```