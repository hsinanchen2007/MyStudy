### 解题思路


### 代码

```python3
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        while num!=1:
            if num%4==0 and num!=0:
                num=num/4
            else:
                return False
        return True
            

```