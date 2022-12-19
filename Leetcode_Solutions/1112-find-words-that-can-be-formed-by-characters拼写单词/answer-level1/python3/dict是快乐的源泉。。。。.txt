### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        count = {}
        for c in chars:
            count.setdefault(c, 0)
            count[c] += 1
        print(count)
        sum_o = 0
        for word in words:
            is_ok = True
            wordd = {}
            for c in word:
                wordd.setdefault(c, 0)
                wordd[c] += 1
            for k, v in wordd.items():
                if k not in count.keys():
                    is_ok = False
                    break
                if v > count[k]:
                    is_ok = False
                    break
            if is_ok:
                print(word)
                sum_o += len(word)
        return sum_o
```