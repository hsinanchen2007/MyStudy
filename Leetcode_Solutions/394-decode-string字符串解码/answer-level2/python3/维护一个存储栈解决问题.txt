### 解题思路
维护一个存储栈，存放"k"和"[]"中的字符串（栈中只存放单个字符）
按照题目要求计算即可

### 代码

```python3
class Solution:
    def decodeString(self, S: str) -> str:
        stack = []
        res = ''
        for s in S:
            if s == ']':
                temp = ''#需要重复的字符串
                times = ''#重复的次数
                while stack[-1] != '[':
                    temp += stack.pop()
                stack.pop()
                temp = "".join(list(temp)[::-1])
                while stack and '0' <= stack[-1] and stack[-1] <= '9':
                    times += stack.pop()
                times = "".join(list(times)[::-1])
                if '[' in stack:
                    stack += list((int(times) * temp))
                else:
                    res += int(times) * temp
            else:
                if s >= 'a' and s <= 'z' and '[' not in stack:# stack为空的情况下，直接将字符添加到结果中
                    res += s
                else:
                    stack.append(s)
        return res

```