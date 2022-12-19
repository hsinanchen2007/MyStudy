### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        dic = collections.defaultdict(int)
        for i in A:
            dic[i] += 1
            if dic[i] > 1:
                return i
```