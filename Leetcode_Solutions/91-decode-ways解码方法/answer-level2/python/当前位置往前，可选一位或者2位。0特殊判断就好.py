### 解题思路
 一开始用dfs做的。超时。
  看了别人的dp看不太懂。就自己写了一个/...

### 代码

```python3

class Solution:
    # 其实只是问了个数 并没有说打印全部的序列
    def numDecodings(self, s: str) -> int:
        if not s:
            return 0
        n = len(s)
        # decode[i]表示从 0 到i位置的所有编码数
        decode = [0 for _ in range(n)]
        # 因为是当前位置可以选1 个
        # 也可以选两个
        # 0 的时候特殊考虑
        decode[0] = 1 if s[0] != '0' else 0
        for i in range(1, n):
            # 选择一位  选择两位
            # 1212
            if s[i] == '0':
                # 这个时候只能选择前两位的
                if i - 1 >= 0 and s[i - 1] in ['1', '2']:
                    if i - 2 >= 0:
                        decode[i] = decode[i - 2]
                    else:
                        decode[i] += 1
                continue
            # 选择一位
            else:
                if 1 <= int(s[i]) <= 9:
                    decode[i] += decode[i - 1]
                # 选择两位
                if 10 <= int(s[i - 1:i + 1]) <= 26:
                    if i - 2 >= 0:
                        decode[i] += decode[i - 2]
                    else:
                        decode[i] += 1
        return decode[-1]
```