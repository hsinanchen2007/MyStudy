### 解题思路 而后缀乘积只需要保存在一个值里面
此处撰写解题思路

### 代码

```python

# -*- coding:utf-8 -*-
class Solution:
    def constructArr(self, A):
        if not A:
            return []
        prefix = [1]*len(A)
        prefix[0]=1
        for i in range(1,len(A)):
            prefix[i] = prefix[i-1]*A[i-1]
        cur_suffix = 1
        for i in range(len(A)-1,-1,-1):
            prefix[i] = prefix[i] * cur_suffix
            cur_suffix *= A[i]
        return prefix
        # write code here
```