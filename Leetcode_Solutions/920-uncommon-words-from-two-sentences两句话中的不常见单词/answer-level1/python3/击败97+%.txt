### 解题思路
三行代码，优雅

### 代码

```python3
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        list_temp=A.split()
        list_temp.extend(B.split())
        res=[item for item in list_temp if list_temp.count(item)==1]
        return res

```