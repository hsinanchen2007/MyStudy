执行用时 :36 ms, 在所有 Python3 提交中击败了99.03% 的用户。
内存消耗 :13 MB, 在所有 Python3 提交中击败了100.00%的用户。

```
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        index = 1
        num = 0
        for i in range(len(citations)-1, -1, -1):
            if citations[i] >= index:
                index += 1
                num += 1
            else:
                return num
        return num
```
