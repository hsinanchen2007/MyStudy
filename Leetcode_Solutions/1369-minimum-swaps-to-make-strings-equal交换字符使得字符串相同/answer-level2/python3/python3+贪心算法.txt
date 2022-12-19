### 解题思路
只有两种情况会交换，一种是s1[i] == 'x' and s2[i] == 'y',另一种是s1[i] == 'y' and s2[i] == 'x',
(x,y)和(x,y)交换需要1步，(y,x)和(y,x)交换需要1步，(x,y)和(y,x)交换需要2步
尽量满足(x,y)和(x,y)交换，(y,x)和(y,x)交换，剩下的再(x,y)和(y,x)交换即可
如果（x,y）的数量对2取余不等于(y,x)的数量对2取余，直接返回-1
### 代码

```python3
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        x_y = 0
        y_x = 0
        ans = 0
        for i in range(len(s1)):
            if s1[i] == 'x' and s2[i] == 'y':
                x_y += 1
            if s1[i] == 'y' and s2[i] == 'x':
                y_x += 1
        if x_y % 2 != y_x % 2:
            return -1
        else:
            ans += x_y // 2 + y_x // 2 \
                + x_y % 2 * 2
        return ans
```