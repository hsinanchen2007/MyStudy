### 解题思路


### 代码

```python3
class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        list_1 = []
        list_2 = []
        for mess_index, mess in enumerate(words):
            if mess == word1:
                list_1.append(mess_index)
            if mess == word2:
                list_2.append(mess_index)
        res = 99999
        for num_1 in list_1:
            for num_2 in list_2:
                res_1 = abs(num_1-num_2)
                res = min(res, res_1)
        return res
```