### 解题思路
从两个方向添加

### 代码

```python
class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        j=0
        c=-1
        B=[0]*len(A)
        for i in A:
            if i%2==0:
                B[j]=i
                j=j+1
            else:
                B[c]=i
                c=c-1
        return B

```