```python
def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        return not collections.Counter(ransomNote) - collections.Counter(magazine)
```
统计两个字符串的char，进行减法操作，如果有剩余证明false。