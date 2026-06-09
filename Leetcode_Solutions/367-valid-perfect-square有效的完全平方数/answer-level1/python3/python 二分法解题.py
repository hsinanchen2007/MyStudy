### 解题思路
用二分法的思路，如果中间平方等于num，返回True，小于num，左侧=中间+1
大于num，右侧=mid-1


### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num<2:
            return True
        left,right=0,num//2
        while left<=right:
            mid=(left+right)//2
            tmp=mid**2
            if tmp==num:
                return True
            elif tmp>num:
                right=mid-1
            else:
                left=mid+1
        return False
            

```