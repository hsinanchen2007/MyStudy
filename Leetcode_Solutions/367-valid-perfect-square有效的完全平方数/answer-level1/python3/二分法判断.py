二分查找借用69题思路，先找出num向下的平方根，再判断其平方与num是否相等
![QQ截图20191207164616.png](https://pic.leetcode-cn.com/3da26b3c9b7d5b49b32435b794797fc858c1b19b659049731bdd9326399ae98d-QQ%E6%88%AA%E5%9B%BE20191207164616.png)
```
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num == 1:
            return True
        pre, cur = 0, num
        while pre < cur:
            mid = (pre + cur) // 2
            if mid**2 <= num and (mid+1)**2 > num:
                break
            elif mid**2 > num:
                cur = mid
            else:
                pre = mid
        if mid**2 == num:
            return True
        else:
            return False 
```
