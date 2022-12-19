> 写在前面： 自己想的方法，看了官方题解感觉似乎更好一些，本方法可以作为一种参考

### 解题思路:
    判断先上坡后下坡才返回True，其余情况均返回False

#### 具体实现:
- 设置上坡`isUp`，下坡变量`isDown`,初始化均为`False`
  - ``A[i-1] < A[i]``开始上坡
    - `isUp`设为`True`
    - 若此时已下过坡`isDown == True`，直接返回`False`
  - `A[i-1] > A[i]`开始下坡
    - `isDown` 设为`True`
    - 若此时还没下过坡``isUp == False``,直接返回`False`
  - ``A[i] == A[i-1]``
    - 直接返回False
- 返回 ``isUp and isDown``

### 代码 (Python3)

```

class Solution:
    def validMountainArray(self, A: List[int]) -> bool:

        isUp, isDown = False, False

        for i in range(1, len(A)):
            # 上坡
            if (A[i] - A[i-1]) > 0:
                # 已经下过坡了
                if isDown:
                    return False
                isUp = True
            # 下坡
            elif (A[i] - A[i-1]) < 0:
                # 还没上过坡
                if not isUp:
                    return False
                isDown = True
            else:
                return False

        return isUp and isDown

```