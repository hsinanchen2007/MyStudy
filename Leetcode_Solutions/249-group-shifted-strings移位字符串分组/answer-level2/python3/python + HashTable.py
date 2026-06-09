```python
class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        hash_table = collections.defaultdict(list)
        for s in strings:
            key = self.getKey(s)
            hash_table[key].append(s)

        return [val for val in hash_table.values()]

    def getKey(self, s) -> str:
        # a-> 0, b = 1, z-> 25
        # z - a = 25
        # ( a - b  + 26 ) % 26 = 25
        res = ''
        for i in range(1, len(s)):
            gap_str = str((ord(s[i]) - ord(s[i - 1]) + 26) % 26)
            res += gap_str.zfill(2)
        return res

```