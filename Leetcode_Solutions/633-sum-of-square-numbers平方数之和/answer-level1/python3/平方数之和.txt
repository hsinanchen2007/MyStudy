### 解题思路
逆向循环

### 代码

```python3
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        j = int(math.sqrt(c))
        i = 0
        while i <= j:
            if c == i**2 + j**2:
                return True
            elif i**2 + j**2>c: # 如果大了，就减小右边的数
                j = j - 1
            else:      # 如果小了，就增加左边的数
                i = i + 1

# 作者：_play_with_pointer

        # if c == 1:
        #     return False
        # for i in range(c//2+1):
        #     for j in range(c//2+1):
        #         if (i**2 + j**2) == c:
        #             return True
        # return False
```