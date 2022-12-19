### 解题思路
两次遍历：
第一次，从后到前遍历，先填从j位置之后的所有数的乘积
第二次，从前往后遍历，再乘以j位置之前的所有数的乘积

### 代码

```python3
class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        if not a:
            return []
        if len(a)==1:
            return [0]
        b=[1]*len(a)
        for i in range(len(b)-2,-1,-1):
            b[i]=b[i+1]*a[i+1]
        tmp=a[0]
        for j in range(1,len(a)):
            b[j]=tmp*b[j]
            tmp=tmp*a[j]
        return b



```