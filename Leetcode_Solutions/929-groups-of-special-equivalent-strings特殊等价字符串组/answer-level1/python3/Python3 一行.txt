```
class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        return len(set("".join(sorted(a[::2]) + sorted(a[1::2])) for a in A))
```

借鉴网友的说法，题目意思为两个字符串的：偶数位置的字符排序后相同；奇数位置的字符排序后也相同。则为特殊等价字符串组。