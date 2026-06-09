### 解题思路
开始理解成把0全给删掉了，但是测试用例里面有-1,0,0的情况，在中间的0是要保留的
如果是删0的情况，有个需要注意的点，
如果是pop()或者是del()
每一次删一个0，A剩下的元素的标号全往前挪了了，导致会漏删，所以删0的话应该倒过来删。比如
lst = [0, 1, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 1, 0, 44, 1, 0]
for i in reversed(range(len(lst))):
    if(lst[i] == 0):
        del lst[i]
这样就不会出现往前挪的问题，
因为是从后往前删的
### 代码

```python
class Solution(object):
    def merge(self, A, m, B, n):
        """
        :type A: List[int]
        :type m: int
        :type B: List[int]
        :type n: int
        :rtype: None Do not return anything, modify A in-place instead.
        """
        A[m:]=B[0:n]
        A.sort()
```