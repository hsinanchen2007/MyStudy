### 解题思路
每次统计0和1的个数，取较小的累加。

### 代码

```python3
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        sums = 0
        count_0 = 0
        count_1 = 0
        current = 0
        for i in range(len(s)-1):
            
            
            if s[i] == '0':
                count_0 += 1
                current = 0
            else:
                count_1 += 1
                current = 1
            
            if s[i] != s[i+1]:
                sums += min(count_0,count_1)
                if current:
                    count_0 = 0
                else:
                    count_1 = 0
        if s[-1] == '0':
            count_0 += 1
        else:
            count_1 += 1

        sums += min(count_0,count_1)           
        return sums
```