### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def climbStairs(self, n):
        if n==1:return 1
        if n==2:return 2
        a=1 ;b=2 ;i=2
        while i<n:
            a=b+a
            a,b=b,a
            i+=1
        return b

```