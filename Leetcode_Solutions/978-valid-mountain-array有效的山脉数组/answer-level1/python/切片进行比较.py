### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def validMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        if len(A) <3:
            return False
        max_index = A.index(max(A))
        first_p = A[:max_index+1]
        second_p = A[max_index:]
        a = 0
        if len(first_p) ==1 or len(second_p) == 1:
            return False
        while a< len(first_p)-1:
            if first_p[a+1] - first_p[a] <=0:
                return False
            a +=1
        a=0
        while a< len(second_p)-1:
            if second_p[a]-second_p[a+1]<=0:
                return False
            a+=1
        return True
```