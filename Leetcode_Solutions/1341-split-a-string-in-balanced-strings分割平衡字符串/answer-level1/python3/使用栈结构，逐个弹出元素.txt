### 解题思路
1. 建立一个字典`temp = {'R': 0, 'L': 0}`用来记录已经弹出的元素个数
2. 如果弹出的‘R’与‘L’个数相同，就可以拆分为一组。

### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        s_list = list(s)
        temp = {'R': 0, 'L': 0}
        total = 0

        while len(s_list) > 0:
            char = s_list.pop()
            temp[char] += 1
            # 判断‘R’与‘L’个数是否相同，如果相同就可以拆分为一组
            if len(set(temp.values())) == 1:
                total += 1
                temp = {'R': 0, 'L': 0}
        
        return total
```