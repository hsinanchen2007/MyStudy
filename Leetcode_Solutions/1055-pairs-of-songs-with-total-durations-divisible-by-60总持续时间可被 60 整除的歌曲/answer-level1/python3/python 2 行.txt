### 解题思路
用哈希表存储不同余数的个数

### 代码

```python3
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        dic = collections.Counter(T % 60 for T in time)
        return dic[0] * (dic[0] - 1) // 2 + dic[30] * (dic[30] - 1) // 2 + sum(dic[i] * dic[60-i] for i in range(1, 30))
```