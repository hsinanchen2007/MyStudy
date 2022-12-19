这道题思路简单，如果要写短自然有写短的方法，但为了效率，多写一点东西是很必要的

首先我们需要记录每个位置的字母是不是最后一次出现

同时，需要判断in关系的都用哈希实现，这样便能最大化效率

```python
class Solution:
    def smallestSubsequence(self, text: str) -> str:
        alphas, last = set(), []  # 记录当前已有字符和该字符是否最后一次出现
        for t in reversed(text):
            if t not in alphas:
                last.append(True)
                alphas.add(t)
            else:
                last.append(False)
        last.reverse()
        # 记录当前入选的序列，其包含的字符以及后续不会再有的字符
        stack, alphas, ended = [], set(), set()
        for s, end in zip(text, last):
            if end:  # 如果不会再有，标记其不可移除
                ended.add(s)
            if s not in alphas:  # 当前序列不存在该字符才考虑
                while stack and stack[-1] > s and stack[-1] not in ended:  # 前一个字符字母序更大且还未结束
                    alphas.remove(stack.pop())  # 弹出，同时移除包含字符的哈希
                stack.append(s)  # 将当前字符加入序列
                alphas.add(s)  # 将当前字符加入包含字符
        return ''.join(stack)
```
