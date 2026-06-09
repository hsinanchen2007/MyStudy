1.首先将数字转成字符，然后遍历整个字符串，将每个字符转成数字，求和
2.判断这个求和后的数字是否在set中，如果在,表示死循环，返回 False，如果不在，判断是否为1.
3.如果不为1，则继续上面的步骤。
代码如下：

```python []
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        nums = set()                
        while n != 1:                 
            n = sum([int(i)**2 for i in str(n)]) 
            if n not in nums:       
                nums.add(n)
            else:                  
                return False
        return True    
```

