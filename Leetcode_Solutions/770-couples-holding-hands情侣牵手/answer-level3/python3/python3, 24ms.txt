### 解题思路
遍历row，把没有匹配的人交换到他或她另一半旁边，保证每次交换都能至少保证一对夫妇匹配。

### 代码

```python3
class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        ans = 0
        for i in range(len(row)):
            while row[i^1] != row[i]^1:
                tar = row[i^1]^1
                for j in range(i+1, len(row)):
                    if row[j] == tar:
                        row[j], row[i] = row[i], row[j]
                        ans += 1
                        break
        return ans
```