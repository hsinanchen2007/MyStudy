### 解题思路
输入的字符串看作MapReduce中Map阶段排好序输出到Reduce阶段的结果，使用Reduce的思路解题即可。

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        cur = ""
        res = ""
        count = 0

        for _ in S:
            if _ == cur:
                count += 1
            if not cur:
                cur = _
                count = 1
            if _ != cur:
                res += cur
                res += str(count)
                cur = _
                count = 1
        // 最后一个字符的输出
        res += cur
        res += str(count)
        if len(res) >= len(S):
            return S
        return res

```