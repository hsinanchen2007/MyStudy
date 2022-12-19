### 解题思路
> 直接一次遍历解决，遇到不同字符时记录上一个字符的个数； 注意最后边界的处理即可

### 代码

```python3
class Solution:
    def compressString(self, s: str) -> str:
        if len(s) <= 2:
            return s
        last = 0
        res = []
        for i in range(1, len(s)):
            if s[i] != s[last]:
                res.append("{}{}".format(s[last], i - last))
                last = i
        res.append("{}{}".format(s[last], len(s) - last))
        res_str = "".join(res)
        if len(res_str) < len(s):
            return res_str
        return s
```

# 运行情况
```
执行用时 :56 ms, 在所有 Python3 提交中击败了76.25%的用户
内存消耗 :15.4 MB, 在所有 Python3 提交中击败了100.00%的用户
```