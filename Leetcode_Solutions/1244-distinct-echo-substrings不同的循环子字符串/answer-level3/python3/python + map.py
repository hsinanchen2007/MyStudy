```python
class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        dic = collections.defaultdict(list)
        res = set()
        for i, t in enumerate(text):
            if t not in dic:
                dic[t].append(i)
            else:
                for pre in dic[t]:
                    gap = i - pre
                    if i + gap <= len(text) and text[pre: pre + gap] == text[i: i + gap]:
                        res.add(text[pre: pre + gap])
                dic[t].append(i)
        return len(res)
```