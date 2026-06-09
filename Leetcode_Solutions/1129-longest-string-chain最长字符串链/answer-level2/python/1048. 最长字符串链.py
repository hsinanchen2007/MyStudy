### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def longestStrChain(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        words.sort(key=len)
        res, note = 0, {}
        for item in words:
            if item not in note:
                note[item] = 1
            for i in range(len(item)):
                temp = item[:i]+item[i+1:]
                if temp in note:
                    note[item] = max(note[temp]+1, note[item])
                res = max(res, note[item])
        return res

```