### 解题思路
刚开始我也是觉得直接用字符串的加法就好了，但是经过评论大神指点，原来在python中的字符串是不可变对象，所以修改和加法操作实际上是新建了一个字符串，在数据量很大的时候就会出现效率低下的问题

解决方法是用列表来存储字符的每一个元素，然后用join拼接一下

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
# 由于字符串类型是不可变的，所以每次使用 + 连接字符串都会生成一个新的字符串，因此数量较大时效率低下
#         ans = ""
#         for i in range(len(s)):
#             if s[i] != " ":
#                 ans += s[i]
#             else:
#                 ans += "%20"
                
#         return ans
        ans  = []
        for c in s:
            if c == " ":
                ans.append("%20")
            else:
                ans.append(c)
        return "".join(ans)
```