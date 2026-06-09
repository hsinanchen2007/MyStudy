### 解题思路
将原有的1-7去掉6和7后将1-5映射到1-10即可，注意满足均匀概率的等可能性。

### 代码

```python3
# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        n=rand7()
        while n>5:
            n=rand7()
        i=rand7()
        while i==4:
            i=rand7()
        if i<4:
            j=0
        else:
            j=5
        return n+j
```

![image.png](https://pic.leetcode-cn.com/184e1221014822ac05cd112d4faf77c563079054f8d5245bda5f57e773da780f-image.png)
