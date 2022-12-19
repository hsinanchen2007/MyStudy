```
class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        if not text or len(text) == 1:
            return 0

        str_set = set()
        for p1 in range(len(text)):
            for p2 in range(p1 + 1, len(text)):
                diff = p2 - p1
                substring = text[p1:p2]
                try:
                    if substring == text[p2:p2 + diff] and substring not in str_set:
                        str_set.add(substring)
                except IndexError:
                    break

        return len(str_set)

```
