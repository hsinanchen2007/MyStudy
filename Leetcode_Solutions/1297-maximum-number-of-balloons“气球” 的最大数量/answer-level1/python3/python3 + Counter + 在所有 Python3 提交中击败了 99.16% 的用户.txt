执行用时 :40 ms, 在所有 Python3 提交中击败了99.16%的用户

内存消耗 :13.7 MB, 在所有 Python3 提交中击败100.00%的用户

气球的最大数量由最少的单子决定的，分别统计5个字母的个数，以及可以组成的balloon的个数，找出可以组成balloon最少的。

```python
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        from collections import Counter
        text_count = Counter(text)
        balloon_dict = {
            'a': 1,
            'b': 1,
            'n': 1,
            'l': 2,
            'o': 2
        }
        result = []
        for key in balloon_dict.keys():
            if key in text_count:
                result.append(int(text_count[key]/balloon_dict[key]))
            else:
                return 0
        return min(result)
```
