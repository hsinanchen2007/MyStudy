### 解题思路
转化为遇到"R"则count+1,遇到"L"则count-1,若count = 0时,则次数+1即可。

### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        sums = 0
        count = 0
        for x in s:
            if x == 'R':
                count += 1
            else:
                count -= 1
            if count == 0:
                sums += 1
        return sums
```