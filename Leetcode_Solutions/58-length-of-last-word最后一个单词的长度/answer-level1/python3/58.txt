### 解题思路
1、先去除字符串首尾空格；
2、处理特殊情况：字符串为空返回0，字符串长度为1返回1；
3、从后到前倒序遍历字符串，非空格就+1，空格就跳出循环，返回结果。

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s_input = s.strip()
        if len(s_input) == 0:
            return 0
        if len(s_input) == 1 and s_input[0] != " ":
            return 1
        out_s = ""
        for i in range(len(s_input), -1, -1):
            if i-1>=0:
                if s_input[i-1] != " ":
                    out_s += s_input[i-1]
                else:
                    break
        return len(out_s)
```