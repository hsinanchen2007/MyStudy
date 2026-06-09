### 解题思路
从头到尾遍历s,用count统计LR字符数量。
为L时候减1，为R的时候+1
每一次统计完count,如果count==0那么前面一段‘LR’字符串可以组合成为平衡的字符串
### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        ans = 0
        count = 0
        for i in s:
            if i == 'L':
                count -= 1
            if i == 'R':
                count += 1
            if count == 0:
                ans += 1
        return ans
```