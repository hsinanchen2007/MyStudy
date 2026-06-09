### 解题思路
此处撰写解题思路

### 代码

```python
# -*- coding:utf-8 -*-
class Solution:
    def sumNums(self, n):
        ans =n
        temp=  ans and (self.sumNums(n-1))
        ans = ans + temp
        return ans
```

```python
class Solution:
    def sumNums(self, n: int) -> int:

        return n and n+ self.sumNums(n-1)  
```