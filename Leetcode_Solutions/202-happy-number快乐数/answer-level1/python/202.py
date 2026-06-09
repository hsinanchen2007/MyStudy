### 解题思路
1、此处用递归计算；
2、递归结束条件：出现各位数4，则返回False（找规律）。

### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        s = str(n)
        if len(s) == 1 and int(s[0]) == 4:
            return False
        sum_num = 0
        for i in range(len(s)):
            sum_num += int(s[i]) ** 2
        if sum_num == 1:
            return True
        return self.isHappy(sum_num)
```