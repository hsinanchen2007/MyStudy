### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        return [[x[i] for x in A] for i in range(len(A[0]))]
        
```