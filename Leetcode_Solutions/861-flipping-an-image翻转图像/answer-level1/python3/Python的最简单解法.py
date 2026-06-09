# Python简单易懂的解法
```
class Solution:
    def flipAndInvertImage(self, A):
        for row in A:
            row.reverse()
            for index,val in enumerate(row):
                row[index] = 1 if val == 0 else 0
        return A
```

