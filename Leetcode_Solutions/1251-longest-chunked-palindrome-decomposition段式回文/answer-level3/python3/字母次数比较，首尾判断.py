-   分别设计两个数组
    -   保存从前开始各个字母的出现次数
    -   保存从后开始各个字母的出现次数
-   只要次数匹配，则进行分割
-   中间的部分特别处理即可



```python
class Solution:
    def longestDecomposition(self, text: str) -> int:
        if not text:
            return 0

        ans = 0
        length = len(text)
        left = [0] * 26
        right = [0] * 26
        start = 0
        end = length // 2

        if length <= 1:
            return 1
        pos = -1
        for i in range(start, end):
            left[ord(text[i]) - 97] += 1
            right[ord(text[-i - 1]) - 97] += 1
            if left == right:
                ans += 2
                pos = i

        if pos < (end - 1):
            ans += 1
        elif length % 2:
            ans += 1

        return ans
```


