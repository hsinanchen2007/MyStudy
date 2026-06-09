### 解题思路
建map，遍历求差，依据差值是否大于零分类讨论。不建议用这个方法，还是二分法更普适一些。

### 代码

```python3
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        strs = 'abcdefghijklmnopqrstuvwxyz'
        dic = {}
        for index, s in enumerate(strs):
            dic[s] = index
        min_neg = 0
        min_pos = 26
        for letter in letters:
            if dic[letter] - dic[target] > 0:
                min_pos = min(dic[letter] - dic[target], min_pos)
            elif dic[letter] - dic[target] < 0:
                min_neg = min(dic[letter] - dic[target], min_neg)
        if min_pos < 26:
            return strs[dic[target] + min_pos]
        else:
            return strs[dic[target] + min_neg]

```