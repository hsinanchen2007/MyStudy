### 解题思路
我的思路：
1. 暴力循环：时间o(N^2)，空间o(1)
2. 双指针法：时间o(N)，空间o(1)
代码展示的是双指针法

### 代码

```python3
class Solution:
    def compress(self, chars: List[str]) -> int:
        if chars == ['']:
            return 0
        counts = 1
        zhizhen = 0

        for i in range(0,len(chars)-1):
            if chars[i] == chars[i+1]:
                counts += 1
            else:
                chars[zhizhen] = chars[i]
                if counts != 1: 
                    counts = str(counts)
                    for x in counts:
                        zhizhen += 1
                        chars[zhizhen] = x
                zhizhen += 1
                counts = 1
        chars[zhizhen] = chars[len(chars)-1]
        if counts != 1:
            counts = str(counts)
            for x in counts:
                zhizhen += 1
                chars[zhizhen] = x

        len_new = zhizhen + 1  
        return len_new
```