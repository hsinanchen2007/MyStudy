### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        def fun(n):
            res=0
            while(n):
                tmp=n%10
                res+=pow(tmp,2)
                n=n//10
            return res
        nums=[]
        nums.append(n)
        while(n):
            n=fun(n)
            if n==1:
                return True
            if n in nums:
                return False
            nums.append(n)

```