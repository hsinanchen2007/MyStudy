### 解题思路
来自评论区的方法做改动；
zip/set/map/list，都用上了

### 代码

```python
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs: return ""

        chars = map(set, zip(*strs))
        result_chars = []
        for char_set in chars:
            if len(char_set) == 1:
                result_chars.append(list(char_set)[0])
            else:
                break
        return "".join(result_chars)
```