### 解题思路
执行用时: 3792 ms, 在所有 Python3 提交中击败了31.60%的用户
内存消耗: 13.8 MB, 在所有 Python3 提交中击败了100.00%的用户

### 代码

```python3
class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        if len(text) < 2:
            return 0

        all_s = set()
        for i in range(0, len(text)-1):
            for j in range(i, len(text)-1):
                sub_s = text[i: j+1]
                if sub_s == text[j+1: 2*j+2-i]:
                    all_s.add(sub_s)
        return len(all_s)
```