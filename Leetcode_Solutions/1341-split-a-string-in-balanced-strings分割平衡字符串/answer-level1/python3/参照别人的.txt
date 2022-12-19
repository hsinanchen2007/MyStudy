### 解题思路
首先题目给的实例是成组的，不要考虑复杂。
条件分析:一对里面L的数量等于R的数量.
思路:遍历数组中L和R的数量，L或者R的数量变化必然是从0到相等再到不相等。

### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
     count = 0
     count_L = 0
     count_R = 0
     for s_ in s :
        if s_ == 'L':
            count_L += 1
        else:
            count_R += 1
        if count_L == count_R:
           count += 1
           count_L = count_R = 0
        else:
         continue
     return(count)
```