### 解题思路
第一次解力扣上的题，一开始看了半天题目。。。感觉后期应该会加快解题速度了

### 代码

```python3
import random

class Solution:
    def game(self, guess, answer):
        count = 0
        for i in range(3):
            if guess[i] == answer[i]:
                count += 1
        return count
```