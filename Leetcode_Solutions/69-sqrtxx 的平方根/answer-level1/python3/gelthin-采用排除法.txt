### 解题思路
这一题似乎用传统三分的方法无法求解， 判断二次，按照结果返回
return mid or
left = mid+1 or 
right = mid-1 会漏解，

例如 mid = 2, result= 8, 导致 left = mid +1 = 3 导致错误。

于是乎，我把排除法和传统的三分方法结合起来也错误。

但是若不想那么多，只用排除法，则不会错。
看来我在[排除法题解下的评论](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/245344) 并不正确
以及在题 [704. 二分查找](https://leetcode-cn.com/problems/binary-search/solution/pai-chu-fa-chuan-tong-fang-fa-by-gelthin/) 下写的题解不一定正确

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 1:
            return x
        left, right = 1, int(x/2)+1
        while left < right:
            mid = (left+right+1)//2
            if mid*mid > x:
                right = mid-1
            else:
                if mid*mid == x:
                    return mid
                else:
                    # left = mid + 1   # 这里还是有 bug
                    left = mid 
        return left
        
```