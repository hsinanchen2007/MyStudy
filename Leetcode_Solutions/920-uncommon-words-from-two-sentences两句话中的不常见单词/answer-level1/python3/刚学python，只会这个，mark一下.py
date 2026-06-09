### 解题思路

只会这个，加油！

### 代码

```python3
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        S1 = A.split()
        S2 = B.split()
        list1 = []
        for i in S1:
            if i not in S2 and S1.count(i) == 1:
                list1.append(i)
        for j in S2:
            if j not in S1 and S2.count(j) == 1:
                list1.append(j)
        return (list1)

```