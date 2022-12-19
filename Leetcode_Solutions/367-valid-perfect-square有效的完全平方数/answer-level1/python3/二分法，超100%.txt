### 解题思路
![批注 2019-12-24 221906.png](https://pic.leetcode-cn.com/1de70a440aace638c00361bbc0d0556fc4e8df1b29013a91bef27e229a1def98-%E6%89%B9%E6%B3%A8%202019-12-24%20221906.png)
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num == 1:return True
        l, e, h = 1, (num + 1) // 2, num
        while h - l > 1:
            if e * e < num:
                l = e
                e = (l + h) // 2
            elif e * e > num:
                h = e
                e = (l + h) // 2
            else:
                return True
        return False
```