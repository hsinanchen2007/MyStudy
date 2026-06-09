# 思路：
1. 先排序，对`words`的每一个字符串`w`按照从大到小排列
2. 如果`words`中的某个字符`w`，使得`w+'#'`不在`S`中，则`S`中需要加入`w+'#'`；否则跳过

# 代码：

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        S = ''
        # 从大到小排序
        words.sort(key=lambda x:len(x), reverse=True)
        for w in words:
            # 必须是 w+'#'，不能是仅是w
            if w + '#' not in S:
                S += w + '#'
        return len(S)
```