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
        if len(A)<3:
            return False




        max_A = max(A)
        a = A.index(max_A)
        first_part = A[:a+1]
        second_part = A[a:]
        numbers_2 = collections.Counter(first_part)
        numbers_3=  collections.Counter(second_part)
        b = sorted(first_part) 
        c = sorted(second_part,reverse=True)
        for i in numbers_2.values():
            if i >=2:
                return False
        for i in numbers_3.values():
            if i >=2:
                return False        
        if len(second_part)==1 or len(first_part)==1:
            return False
        if b== first_part and c == second_part:
            return True
        return False

```