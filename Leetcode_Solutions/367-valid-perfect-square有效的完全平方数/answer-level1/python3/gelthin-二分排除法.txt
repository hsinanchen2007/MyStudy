### 解题思路
非常简单。

这里恰好 if 条件之后是 left=mid+1
不过最后还需要判断一下，因为不一定能找到。

### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num == 0:
            return False
        if num == 1:
            return True
        a, b = 1, num//2+1
        while a<b:
            mid = a + (b-a)//2
            if mid*mid < num:
                a = mid+1
            else:
                b = mid
        if a*a == num:
            return True
        else:
            return False



```